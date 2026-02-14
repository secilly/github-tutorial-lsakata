// Lily Sakata
// A424161
// rhymes.cpp

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // for exit
using namespace std;

typedef string* StrPtr;

// FUNCTION DECLARATIONS
string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {

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
    int size(1), i(0);
    string line;
    StrPtr array = new string[size];
    StrPtr newArray = nullptr;

    while (!lineInput.eof()) {
        
        getline(lineInput, line);
        string lastWord = findLastWord(line);
        cleanUp(lastWord);

        // adds unformatted word to array
        array[i] = lastWord;
        i++;

        // when no space left in array
        if (i == size) { 
            
            // create new array with more space
            newArray = new string[size + 1];

            // copy old array to new array
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            } // for end

            delete [] array;
            array = newArray;

            size++;
        }

    } // while end

    size--; // get rid of extra indice at the end
    
    // Finally, print the results (see lab descriptions for examples)

    int count(0);
    for (int i = 0; i < size; i++) {
        if (compareWords(array[i], array[i+1]) && i < size - 1) {
            cout << array[i] << " and " << array[i+1] << endl;
            count++;
        }
        else if (compareWords(array[i], array[i+1]) && i == size - 1)
            cout << array[i] << " and " << array[i+1] << endl;
            count++;
    } // for end i

    if (count > 1) {
        cout << "There are " << count << " pairs of rhyming words." << endl;
    }
    else if (count == 1) {
        cout << "There is " << count << " pair of rhyming words." << endl;
    }
    else {
        cout << "No rhymes found." << endl;
    }
    
    double density = count/size;
    cout << "There are " << size << " lines in this poem, so the rhyme-line density is: " 
        << density << endl;

    delete [] array;
    delete [] newArray;

    return 0;
}

// FUNCTION DEFINITIONS
// Pre-Condition: takes in a line of strings
// Post-Condition: returns a string of the last word of the input line
string findLastWord(string line) {
    
    int size = line.size();
    int rposition = line.rfind(" ");

    // takes last word from when last space occured to end of line
    string lastWord = line.substr(rposition + 1, (size - 1) - rposition);
    
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
