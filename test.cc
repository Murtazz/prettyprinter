#include <iostream>
#include <utility>
#include <string>

using namespace std;


void insertTab(string &str, int nSpc) {
        int space = 0;
        while (space != nSpc) {
                str += " ";
                space += 1;
        }
}

int main() {
        string c;
        string prevC;
        string prettyCode;
        string comment;
        int spcCount = 0;
        while (true) {
                prevC = c;
                cout << c;
                if (!(cin >> c)) {
                        if (cin.eof()) break; // If we've reached EOF we're done
                }
                if (c == "{") {
                        spcCount += 1;
                        prettyCode += c;
                        prettyCode += "\n";
                        //if (cin.peek() == ' ') {
                        insertTab(prettyCode, spcCount);
                        
                        // cout << prettyCode << endl;
                        // cout << spcCount << endl;
                } else if (c == "}") {
		  	spcCount -= 1;
			insertTab(prettyCode, spcCount);
                        //prettyCode.erase(prettyCode.length() - 1);
                        prettyCode += c;
                        prettyCode += "\n";
                } else if (c == ";") {
                        prettyCode += c;
                        prettyCode += "\n";
                     
                        insertTab(prettyCode, spcCount);
                        
                        //insertTab(prettyCode, spcCount-1);
                } else if (c == "//") {
                        //prettyCode.erase(prettyCode.length() - 1);
                        //insertTab(prettyCode, spcCount);
                        prettyCode += c;
                        getline(cin, comment);
                        prettyCode += comment;
                        prettyCode += "\n";
                        insertTab(prettyCode, spcCount);
                } else {
			prettyCode += " ";
                        prettyCode += c;
                }
        }
        prettyCode.erase(prettyCode.length() - 1);
        cout << prettyCode;
}

