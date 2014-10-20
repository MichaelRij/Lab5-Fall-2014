#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>

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
Can only handle a-z and A-Z, ignores everything other than letters space, and linebreak;
forces all letters to lowercase; 
uses non-alphabetic characters to determine a new word; exception for '
does not spellcheck;

Differences from Dictionary(1)
Functions will be in a seperate linked file
Dictionary will be sorted before being printed
Will hold words of any length
*/

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

/*
  note that these are global variables so that they are already initialized to 0
*/

DICT dictionary;  //your dictionary 
WORD word;        // 
int myCount[MAX];   //tracks word frequencies
int tracker = 0;

void DumpDictionary(DICT dict, int count[]) {
/* 
  will sort the dictionary, and display the contents
*/
    sort(dict,dict+tracker);
    int tab = 0; 
    cout<<"Word		Frequency\n";
    cout<<"--------------------------\n";

    for(int i=0; i < tracker; i++){

	if(dict[i] == "")break;

	cout << dict[i];

	tab=((23-dict[i].length())/8);// 		lines up the counts
//	if(dict[i].length()%8==7)tab++;// 	handles a special case
	while(tab-->=0)cout << "	";
	cout << myCount[i]<<endl;
    }
}

BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/

    int pos = LocateWord(dict, word);

    if(!FullDictionary(dict)) return 0;
    if(pos<0) pos = tracker++;
    
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
	}else if (ch == 39)continue;
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

    for(int i=0;i<tracker;i++){
	if(dict[i]=="")break;
	if(dict[i]==word)return i;
    }
    return -1;
}

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( "" == word )  {
           DumpDictionary(dictionary,myCount);
           break;
       }
	pos = LocateWord(dictionary,word);
       if (pos >=  0 ) 
           myCount[pos]++;
       else{
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
	}
    }
cout << dictionary[0]<<" was stored in the array"<< endl;
    return 0;
}
