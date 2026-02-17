// Lily Sakata
// A424161
// rhymes.cpp

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // for exit
#include <iomanip> // for precision
using namespace std;

typedef string* StrPtr;

// FUNCTION DECLARATIONS
string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {

    cout << fixed << showpoint;
    cout << setprecision(2);

    // Create input stream object
    ifstream lineInput;
    string poemFile;
    cout << "Enter filename: "; 
    cin >> poemFile;
    lineInput.open(poemFile);

    // Check input file name from user
    if (lineInput.fail()) {
        cerr << "Cannot open: " << poemFile << endl;
        exit(1);
    }

    // Declare variables and arrays
    int size(1), i(0), lineCount(0);
    string line;
    StrPtr array = new string[size];
    StrPtr newArray = nullptr;

    // runs until end of file
    while (!lineInput.eof()) {
        
        // takes a line at a time
        getline(lineInput, line);
        lineCount++;
    
        // skips blank lines
        if (line.empty()) {
            continue;
        }
    
        // finds and cleans up last word in the line
        string lastWord = findLastWord(line);
        cleanUp(lastWord);
    
        // skip if cleanUp erased word
        if (lastWord.empty()) {
            continue;
        }
        
        // when no space left in array
        if (i == size) { 

            size++;
            
            // create new array with more space
            newArray = new string[size];

            // copy old array to new array
            for (int j = 0; j < size - 1; j++) {
                newArray[j] = array[j];
            } // for end

            delete [] array;
            array = newArray;
        }

        array[i] = lastWord;
        i++;

    } // while end

    lineInput.close();
    
    //size--; // get rid of extra indice at the end
    
    // Finally, print the results (see lab descriptions for examples)

    // Print out rhyming pairs and count them
    int rhymeCount(0);
    for (int i = 0; i < size - 1; i++) {
        if (compareWords(array[i], array[i+1])) {
            cout << array[i] << " and " << array[i+1] << endl;
            rhymeCount++;
        }
    } // for end 

    // Prints specific lines depending on number of rhyming pairs
    double density = static_cast<double> (rhymeCount) / lineCount;
    if (rhymeCount > 1) {
        cout << "There are " << rhymeCount << " pairs of rhyming words." << endl;
    }
    else if (rhymeCount == 1) {
        cout << "There is " << rhymeCount << " pair of rhyming words." << endl;
    }
    else {
        cout << "No rhymes found." << endl;
    }
    
    cout << "There are " << lineCount << " lines in this poem";
    if (rhymeCount > 0) {
        cout << ", so the rhyme-line density is: " << density << endl;
    }
    else {
        cout << "." << endl;
    }

    delete [] array;
    delete [] newArray;
    
    return 0;

} // main end

// FUNCTION DEFINITIONS
// Pre-Condition: takes in a line of strings
// Post-Condition: returns a string of the last word of the input line
string findLastWord(string line) {
    
    int rposition = line.rfind(" ");

    // if no space occurred then takes the whole line 
    if (rposition == string::npos) {
        return line;
    }

    // takes last word from when last space occured to end of line
    return line.substr(rposition + 1);

} // def end

// Pre-Condition: takes in a string by reference
// Post-Condition: formats string to be only lowercase letters
void cleanUp(string &word) {

    int size = word.size();
    for (int i = 0; i < size; i++) {
        
        if (isalpha(word[i])) { // if letter converts to lower case
            word[i] = tolower(word[i]);
        } 
        else { // deletes if not a letter
            word.erase(i, 1);
            i--;
        }

    } // for end

} // def end

// Pre-Condition: takes in two strings
// Post-Condition: returns true if the last two letters in the words match each other
bool compareWords(string word1, string word2) {
    
    int size1 = word1.size();
    int size2 = word2.size();

   // compares the last two letters in each word together
    if ( word1[size1 - 1] == word2[size2 - 1] && word1[size1 - 2] == word2[size2 - 2] ) {
        return true;
    }
    else {
        return false;
    }

} // def end
