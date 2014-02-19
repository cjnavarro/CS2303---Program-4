/*******************************************************************************************
 *
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
                                 
