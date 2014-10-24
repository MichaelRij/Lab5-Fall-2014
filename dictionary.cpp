#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

/*
Author : Michael Rijlaarsdam
Lab #5 Assignment #2 Dictionary2
Purpose : This program creates a list of all the words typed in or in a given text file. cmd ./prog < "text file"
Can only handle a-z and A-Z;
forces all letters to lowercase; 
uses non-alphabetic characters to determine a new word; exception for '
does not spellcheck;

Differences from Dictionary(1)
Functions will be in a seperate linked file
Dictionary will be sorted before being printed
Will hold words of any length
*/

//Prototypes
void sortDictionary(int, int);
void DumpDictionary(DICT ,int[]);
int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);

/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int myCount[MAX];   //tracks word frequencies
int tracker = 0; // tracks the first available slot

int rec = 0;

void sortDictionary(int start, int length) {
//uses quicksort; does the same operations to the count array as the dict

cout << rec++ << endl;

    BOOL done = 0;
    int i=start,j=start + length-1, p = (length-1)/2+start, res, tint;//left, right, pivot, result, temp int
    WORD pVal = dictionary[p],tmp;

    while(!done){
if(rec < 13){// 
 cout<<"pVal "<<p<<" = "<<pVal<<p<<"<--------------"<<endl;
 cout << "i= "<< start <<"  j= "<<start + length-1<<"  length = "<<length << endl;
 for(int ii = start; ii<start+length; ii++)
  cout<<ii<<" = "<<dictionary[ii]<<endl;
}

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

cout << "Swapping " << dictionary[i]<< " with " <<dictionary[j]<<endl;

		    tint = myCount[j];// swap associated counts
		    myCount[j] = myCount[i];
		    myCount[i] = tint;

		    i++;
		    j--;

		    done = 0;
		}
	    }
	}
if(rec < 13){// 
 cout<<"pVal "<<p<<" = "<<pVal<<p<<"<--------------"<<endl;
 cout << "i= "<< start <<"  j= "<<start + length-1<<"  length = "<<length << endl;
 for(int ii = start; ii<start+length; ii++)
  cout<<ii<<" = "<<dictionary[ii]<<endl;
}
    }

/*if(length == 12){
 for(int ii = start; ii<start+length; ii++)
  cout<<ii<<" = "<<dictionary[ii]<<endl;
 cout<<"pVal "<<p<<" = "<<pVal<<p<<"<--------------"<<endl;
}*/
    
    if(p-start+1 >1){
cout<<"send left sublist"<<start<<" "<< p-start+1<<endl;
	sortDictionary(start, p-start+1);
    }

    if((length+1)/2 >1){
cout<<"send right sublist"<<p<<" "<< (length+1)/2<<endl;
	sortDictionary(p+1, length/2);
    }
    
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
