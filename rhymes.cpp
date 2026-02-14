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
    for (int i = 0; i < size - 1; i++) {
        if (compareWords(array[i], array[i+1])) {
            cout << array[i] << " and " << array[i+1] << endl;
            count++;
        }
    } // for end 

    double density = static_cast<double> (count) / size;
    if (count > 1) {
        cout << "There are " << count << " pairs of rhyming words." << endl;
    }
    else if (count == 1) {
        cout << "There is " << count << " pair of rhyming words." << endl;
    }
    else {
        cout << "No rhymes found." << endl;
    }
    
    if (count > 0) {
    cout << "There are " << size << " lines in this poem, so the rhyme-line density is: " 
        << density << endl;
    }
    else {
        cout << "There are " << size << " lines in this poem." << endl;
    }

    delete [] array;

    return 0;
}

// FUNCTION DEFINITIONS
// Pre-Condition: takes in a line of strings
// Post-Condition: returns a string of the last word of the input line
string findLastWord(string line) {
    
    int size = line.size();
    int rposition = line.rfind(" ");

    // if no space occurred then takes the whole line 
    if (rposition == string::npos) {
        return line;
    }

    // takes last word from when last space occured to end of line
    return line.substr(rposition + 1);

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
            i--;
            size--;
        }

    } // for end

} // def end

// Pre-Condition:
// Post-Condition:
bool compareWords(string word1, string word2) {
    
    int size1 = word1.size();
    int size2 = word2.size();

    for (int i = 1; i <= 2; i++) { 
        if (word1[size1 - i] != word2[size2 - i]) {
            return false;
        }
    } // for i
    
    return true;

} // def end
