/*
 * File: main.cpp
 * ------------------
 * Students: Hoang Minh Ngo & Christopher Navarro 
 * Section: C04
 * Program 4
 */


#include <stdlib.h>
#include <iostream>
#include <string>
#include "list.h"


using namespace std;


/* ----------------------------------- CONSTANTS ----------------------------------------- */
#define DELIMITERS " <>?.,/{}[]'|`~!@#$%^&*()"


/* ---------------------------------- MAIN METHODS --------------------------------------- */
void   welcome();
void   openFile(ifstream &file);
string breakString(string &line, string delimiters);
void   toLowerCase(string &line);

int main()
{
   			// Welcome message
        welcome();

        // Open the file and store it
        ifstream inputFile;
        openFile(inputFile);

        int lineCount = 0;
        string line;
        string word;
        Queue<string> words;

        // While the file still has line
        while (getline(inputFile, line)) {
                // Increment line counter
                lineCount++;
           
                // Convert a line to lower case
                toLowerCase(line);

                // Break a line into tokens and Add them to the tree
                while (line != "") {
                        // NEED DATA STRUCTURE
                        word = breakString(line, DELIMITERS);
                        words.enqueue(word);
                }
        }

        string w;
        // Print out the result
        while (!words.isEmpty()) {
                  cout << words.dequeue() << endl;
        }

        return 0;
}

/* --------------------------------- SUPPORT METHODS ------------------------------------- */
/*******************************************************************************************
 *
 * Method: welcome
 * Usage: welcome()
 * ----------------
 * Print out the welcome message
 *
 *******************************************************************************************/
void welcome()
{
        cout << "This is a case-insensitive cross reference generator" << endl;
        cout << "Enter the name of the file in the form of ****.txt" << endl << endl;
}

/*******************************************************************************************
 *
 * openFile: Prompt user for a file name, open that file
 *
 * @parameter: the original ifstream object
 *******************************************************************************************/
void openFile(ifstream &file)
{
        string fileName;

        cout << "Enter the name of the file: ";
        cin  >> fileName;

        file.open(fileName.c_str());
}

/*******************************************************************************************
 *
 * toLowerCase: Convert all characters in a string to lower case
 *
 *******************************************************************************************/
void toLowerCase(string &line)
{
        for (int i = 0; i < line.length(); i++) {
                line[i] = tolower(line[i]);
        }
}

/*******************************************************************************************
 *
 * breakString: get a group of characters from the start of the string to the first
 *              occurence of any characters in the delimiters parameter
 *
 * @parameter: An original string, a string containing delimiter
 *******************************************************************************************/
string breakString(string &line, string delimiters)
{
        string result;
        int initIndex = 0;
        int tokenLength;

        if (line.length()) {
                tokenLength = line.find_first_of(delimiters);
                result = line.substr(initIndex, tokenLength);
                line = line.substr(tokenLength + 1);
        }
        return result;
}
