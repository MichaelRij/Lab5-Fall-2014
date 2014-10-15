#include <cstdio>
#include <cctype>	
#include <iostream>

using namespace std;

/*
Author : Michael Rijlaarsdam
Lab #4 Assignment #1 Dictionary
Purpose : This program creates a list of all the words typed in or in a given text file. cmd ./prog < "text file"
Can only handle a-z and A-Z, ignores everything other than letters space, and linebreak;
forces all letters to lowercase; 
uses space and linebreak to determine a new word;
does not spellcheck;
Words greater than the allowed length are broken up and treated as seperate shorter words
*/

int strLength(int);
int strLengthP(int);
int strLength(void);
void printDict(void);
bool unique(void);
void fillDict(void);

#define  NUMWORDS 100//		Determines how many words can be entered into the list
#define WORDSIZE 22//		Determines how many letters can be in each word 
int word=0;
char dict [NUMWORDS][WORDSIZE]={0};
int dicFreq[NUMWORDS]={0};
bool listFlag = false;

int main() {
	fillDict();
	printDict();
	return 0;
	
}
	
int strLength(int str){ //	with parameter without length error message
	int i=0;
	while(dict[str][i]!=0){
		i++;
		if(i==WORDSIZE)break;
	}
return i;}

int strLengthP(int str){ //	with parameter with length error message only gets run by printDict
	int i=0;
	while(dict[str][i]!=0){
		 i++;
		if(i==WORDSIZE){
			cout << "*";
			break;
		}
	}
return i;}

int strLength(){ // 	no parameter should only runs on dict[word]
	int i=0;
	while(dict[word][i]!=0){
		i++;
		if(i==WORDSIZE)break;
	}
return i;}

void printDict(){ //	Print out the dictionary
	int length = 0,tab=0;
	cout<<"\nNOTE: * means this word has been shortened because it was beyond the allowed length.\n\n";
	cout<<"Word		Frequency\n";
	cout<<"--------------------------\n";
	for(int i=0; i < word; i++){
		length = strLengthP(i);
		for(int j=0; j < length; j++) 
			cout.put(dict[i][j]);
		tab=(WORDSIZE-length)/8;// 		lines up the frequencies
		if(length%8==7)tab++;// 		handles a special case
		while(tab-->=0)cout << "	";
		cout << dicFreq[i]<<"\n";
	}
	if(listFlag) cout<<"\nThe list is full so you cant add any more words. Sorry.\n";
}

bool unique(){//	checks if string is unique; handles empty string; updates dicFreq; moves word along
	bool same = false;
	int length = strLength();
	if(length==0)return false; //			skip if empty string
	for(int i=0;i<word;i++){//			go through the list of previous words 
		if(length==strLength(i)){
			same = true;
			for(int j=0; j < length; j++){  // start checking each letter
				if(dict[i][j]!=dict[word][j]) {
					same = false;
					break;
				}
			}
			if(same){//			the word is alredy in dict
				dicFreq[i]+=1;
				for(int j=0; j < length; j++)// clear dict[word]
					dict[word][j]=0;
				return false;
			}
		}	
	}
	dicFreq[word]=1;//	updates dicFreq; moves word along
	word++;
	return true;
}

void fillDict(){//	fills the dictionary
	int i = 0;
	char ch;
	while( cin.good() ){
		ch = cin.get();
		if ( isalpha(ch) ) { // 		function test if ch  is A-Z, a-z 
			if(ch>64 && ch<=90)ch+=32;//	convert A-Z to a-z
			dict[word][i++]=ch;
		}
		else if (ch==' '||ch=='\n'){//		indicates new word
			unique();
			if(word==NUMWORDS){//		prevents the user from exceeding NUMWORDS
				listFlag = true;
				break;
			}
			i=0;
		}
	}
}

