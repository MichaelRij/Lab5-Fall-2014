#include "dictionary.h"

/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int myCount[MAX];   //tracks word frequencies
int tracker = 0; // tracks the first available slot

void sortDictionary(int start, int length) {
//uses quicksort; does the same operations to the count array as the dict

    BOOL done = 0;
    int i=start,j=start + length-1, p = (length-1)/2+start, res, tint;//left, right, pivot, result, temp int
    WORD pVal = dictionary[p],tmp;

    while(!done){

	i=start;
	j=start + length-1;
	p = (length-1)/2+start;
	pVal = dictionary[p];

	done = 1;
	while (i<j){
	    res = dictionary[i].compare(pVal);
	    if(res<0)i++;
	    else {
		res = dictionary[j].compare(pVal);
		if(res>0)j--;
		else {//swap
		    tmp = dictionary[j];// swap strings
		    dictionary[j] = dictionary[i];
		    dictionary[i] = tmp;

		    tint = myCount[j];// swap associated counts
		    myCount[j] = myCount[i];
		    myCount[i] = tint;

		    i++;
		    j--;

		    done = 0;
		}
	    }
	}
    }

    if(p-start+1 >1)
	sortDictionary(start, p-start+1);

    if((length+1)/2 >1)
	sortDictionary(p+1, length/2);
}

void DumpDictionary(DICT dict, int count[]) {
/* 
  will sort the dictionary, and display the contents
*/    
    sortDictionary(0, tracker);

    int tab = 0; 
    cout<<"Word		Frequency\n";
    cout<<"--------------------------\n";

    for(int i=0; i < tracker; i++){

	if(dict[i] == "")break;

	cout << dict[i];

	tab=((23-dict[i].length())/8);// 	lines up the counts
	while(tab-->=0)cout << "	";
	cout << myCount[i]<<endl;
    }
}




BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

    int pos = LocateWord(dict, word);// is -1 if not found

    if(!FullDictionary(dict)) return 0;
    if(pos<0) pos = tracker++;//	if not found it goes in the first available spot
    
    dict[pos] = word;
    myCount[pos] = 1;
    return 1;
}



WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or 0 if no more words in input stream
*/
    WORD myString;
    BOOL empty = 1;

    char ch;
    while( cin.good() ){
	ch = cin.get();
	
	if(isalpha(ch)){  
	    if(ch>64 && ch<=90)ch+=32;//	convert A-Z to a-z
	    myString.push_back(ch);
	    empty = 0;
	}else if (ch == 39)continue;// handles apostraphes
	else if(!empty) return myString;

    }
    
    return "";

}

BOOL FullDictionary(DICT dict) {

   //if dictionary is full, return 1 else 0 

if(tracker>=100)return 0;
return 1;
}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/

    for(int i=0;i<tracker;i++){//	sequential search
	if(dict[i]==word)return i;
    }
    return -1;
}
