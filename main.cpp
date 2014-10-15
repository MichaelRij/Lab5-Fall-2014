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
Can only handle a-z and A-Z, ignores everything other than letters space, and linebreak;
forces all letters to lowercase; 
uses space and linebreak to determine a new word;
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
int count[MAX];   //tracks word frequencies


BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
/*
}

void DumpDictionary(DICT dict, int count[]) {
/* 
  will sort the dictionary, and display the contents
*/
}

WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or 0 if no more words in input stream
*/
    int length = getNextWordLength();
    if (length==0)return 0;//		checks for empty string

    char ch;
    for (int i = 0; i < length; i++){
	cin.get();
	if(ch>64 && ch<=90)ch+=32;//	convert A-Z to a-z
    }

}

int getNextWordLength(){// <-- self documents
    int i = 0;
    char ch;
    while( cin.good() ){
	ch = cin.get();
	if (ch==' '||ch=='\n'){//		indicates new word
	    return i;
	}
	i++;
    }
    return 0;// 	Can be evaluated as false
}

BOOL FullDictionary(DICT dict) {
/* 
   if dictionary is full, return 1 else 0 
 */
}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/
}

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( 0 == word )  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos == LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}
