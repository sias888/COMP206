//: LineReader.cpp

/*
Title: LineReader.cpp
Description: Reads a text file line-by-line
Date: 2020-05-21
Author: Irteza Shamsi
Version: 2.3
*/

/*
DOCUMENTATION

Purpose: This program opens a text file and reads it line-by-line, waiting for user to press enter after each line ends.

Compile (assuming use of Cygwin): g++ -o LineReader LineReader.cpp
Execute (assuming use of Cygwin): ./LineReader

Classes: none

Variables:
	fileName - string - used to store name of text file to be read
	file - ifstream - infile used to get lines from and open chosen file
	line - string - object of string class used to store lines from infile
	throwaway - string - throwaway string used to ignore user input until [enter] is pressed

*/

/*
TEST PLAN

Normal Case (file exists):
	>please type in the file name: example
	>*file line 1 here*
	>*file line 2 here*
	>...

Bad Case (file doesnt exist):
	>please type in the file name here: DoesNotExist
	>File DoesNotExist does not exist.
*/

#include <iostream> // Stream Declarations
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	string fileName;
	ifstream file;
	string line;
	string throwaway;

	// Request and obtain filename
	cout << "please type in the file name: ";
	cin >> fileName;

	//Add '.txt' to filename if not already present
	if(fileName.find(".txt") == -1) {

		fileName = fileName + ".txt";
    	}
	
	// Open File
	file.open(fileName);

	if(!file.fail()){

		while(getline(file, line)){
			getline(cin, throwaway);
			cout << line;
		}
	}
	else{cout << "File " << fileName<< " does not exist.";}

	return 0;
}