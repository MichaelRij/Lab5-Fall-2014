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

/*
  note that these are global variables so that they are already initialized to 0
*/

extern DICT dictionary;  //your dictionary 
extern WORD word;        // 
extern int myCount[MAX];   //tracks word frequencies
extern int tracker; // tracks the first available slot

//Prototypes
void sortDictionary(int, int);
void DumpDictionary(DICT ,int[]);
int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);

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
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
	
    }
    return 0;
}
