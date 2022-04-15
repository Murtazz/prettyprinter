#include <iostream>
#include <string>

using namespace std;

bool spcCheck(char c) {  // function to check for whitespace
	if (c == ' ' || c == '\t' || c == '\n') {
		return true;
	} else {
		return false;
	}
}

void removeSpace(string &str) {  // function to remove all ' ' from the end of str
	while (str[str.length()-1] == ' ') {
		 str.erase(str.length() - 1);
	}
}

void insertTab(string &str, int nSpc) {  // function to insert nSpc amount of spaces 
        int space = 0;
	while (space != nSpc) {
                str += " ";
                space += 1;
        }
}

int main() {
        char c;
        string prettyCode;
        string comment;
        int spcCount = 0;
	cin >> noskipws;  // so we get all white space inputs
        while (true) {
                if (!(cin >> c)) {  // collect inputs
                        if (cin.eof()) break; // If we've reached EOF we're done
                }
                if (c == '{') {  // check if there is any open squiggly brackets
                        spcCount += 1; // add an indent count so all content within the { bracket has spaces = spcCount
			prettyCode += c; 
                        prettyCode += "\n"; 
			insertTab(prettyCode, spcCount); // insert the required number of spaces
                } else if (c == '}') {  // check for close bracket
		        spcCount -= 1;  // remove 1 spcCount 
                        removeSpace(prettyCode);  
			insertTab(prettyCode, spcCount);   // readjust the spacing before the closing } and insert one less space
                        prettyCode += c;
                        prettyCode += "\n";
                } else if (c == ';') {  // check for ;
                        prettyCode += c;
                        prettyCode += "\n";
                        insertTab(prettyCode, spcCount);
                } else if (c == '/' && (cin.peek() == '/')) {  // check for comments
			prettyCode += c; // add the current forward slash /
                        getline(cin, comment);  // add the rest of the line
                        prettyCode += comment;
                        prettyCode += "\n";
			insertTab(prettyCode, spcCount);
                } else if (spcCheck(c)) { // ignore any given whitespace
			continue;
		}
		 else {
                        prettyCode += c; // add any non whitespace characters
		       if (!(cin.eof()) && spcCheck(cin.peek())) { // check if next char is a whitespace
			       prettyCode += " ";  // if so then add one whitespace
		       }
                }

        }
        cout << prettyCode; // print the fixed code
}

