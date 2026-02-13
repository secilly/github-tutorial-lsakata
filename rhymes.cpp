// Lily Sakata
// A424161
// rhymes.cpp

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // for exit
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {
    // MISSING CODE HERE (you can remove these comments)
    // Create input stream object, then get a filename from user (check it too)
    ifstream lineInput;
    string poemFile;
    cout << "Enter filename: "; 
    cin << poemFile;
    lineInput.open(poemFile);

    if (lineInput.fail()) {
        cerr >> "Cannot open: " >> poemFile >> endl;
        exit(1);
    }
    // Read the lines in your file and check on rhyming, per our definition

    string line;
    while (!lineInput.eof()) {
        getline(lineInput, line);


    }

    // Finally, print the results (see lab descriptions for examples)

    return 0;
}

// FUNCTION DEFINITIONS
// Pre-Condition: takes in a line of strings
// Post-Condition: returns a string of the last word of the input line
string findLastWord(string line) {
    
    int size = line.size();
    int rposition = line.rfind(" ");

    // takes last word from when last space occured to end of line
    string lastWord = line.substr(rposition, size - rposition);
    
    return lastWord;

} // def end

// Pre-Condition: 
// Post-Condition: 
void cleanUp(string &word) {

    int size = word.size();
    for (int i = 0; i < size; i++) {
        
        if (isalpha(word[i]) != 0) { // if letter converts to lower case
            word[i] = tolower(word[i]);
        } 
        else {
            word.erase(i, 1);
            size--;
        }

    } // for end

} // def end

// Pre-Condition:
// Post-Condition:
bool compareWords(string word1, string word2) {
    
    int size1 = word1.size(), size2 = word2.size();
    bool sameLetter = true;
    
    for (int i = size1 - 1; i >= size1 - 3; i--) { 
        for (int j = size2 - 1; j >= size2 - 3; j--) {
            if (word1[i] != word2[j]) {
                sameLetter = false;
            }
        } // for j
    } // for i
    
    if (sameLetter) {
        return true;
    }
    else {
        return false;
    }

} // def end
