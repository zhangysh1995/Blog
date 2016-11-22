// Author: Yushan Zhang
// Project 1

#include <fstream>
#include <iostream>
#include <functional>
#include <string>
#include <thread>
#include <deque>
#include <regex>
using std::string;
using std::cout;
using std::endl;
using std::thread;
using std::deque;

int turn = 0;
bool flag[] = {false, false };
string word;

void printVow(std::ifstream& in);	//function for vow
void printCons(std::ifstream& in);	//function for cons
bool checkWord(string word); //alphabetical check 

int main(int argc, char * argv[])
{
	if(argc != 2)
    {
        cout << "======== nput Argument Number Wrong! "
        	<< "Usage:  *.txt ========" <<endl;
        return 0;
    }
	
	string const file = argv[1];   //get file name
	std::ifstream in(file);	//open file

	thread vow(printVow, std::ref(in));
	thread cons(printCons,std::ref(in));

	if(in.good()) in >> word;	//read first word
	else cout << "======== empty file! ========" << endl;

	if(vow.joinable()) vow.join();
	if(cons.joinable()) cons.join();
}
void printVow(std::ifstream& in)
{
	while(true)
	{
		flag[0]=true;
		turn = 1;

		while(turn==1&&flag[1]);	
			if(checkWord(word))
			{
				if(in.eof()) exit(0);	//if end of file
				else{
					cout << "vow: " << word << endl;	
					in >> word;
				} 
			}	
			flag[0]=false;
			std::this_thread::yield();
	}
}
void printCons(std::ifstream& in)
{
	while(true)
	{
		flag[1]=true;
		turn = 0;

		while(turn==0&&flag[0]);			
			if(!checkWord(word))
			{
				if(in.eof()) exit(0);	//if end of file
				else{
					cout << "cons: " << word << endl;	
					in >> word;
				} 
			}  
			flag[1]=false;	
			std::this_thread::yield();					
	}
}
bool checkWord(string word)	
{
	std::regex pattern("[aAeEiIoOuU][a-zA-Z0-9]*");
	return std::regex_match(word, pattern);
}