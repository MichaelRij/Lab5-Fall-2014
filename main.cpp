#include "dictionary.h"

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
