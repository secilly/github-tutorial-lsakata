// Lily Sakata
// A424161
// anagrams.cpp

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// FUNCTION DECLARATIONS

string unformatString(string str);
int letterCount(string str, char let);
void compareStrings(string str1, string str2);


int main()
{
    string input1, input2; // creates two strings
    cout << "Enter first string:" << endl;
    getline(cin, input1); // input1 is initialized as user input
    cout << "Enter second string:" << endl;
    getline(cin, input2); // input2 is initialized as user input 

    compareStrings(input1, input2); // calls function to compare the two inputs
                                    // and outputs if they are anagrams or not

    return 0;
} // main end

// FUNCTION DEFINITIONS

// Function 1:
// Pre-Conditions: takes in a string
// Post-Conditions: returns the string lowercase and only with letters (alphabetic)
string unformatString(string str) {
 
    string result;
    int size = str.length();

    for (int i = 0; i < size; i++) {
        
        if (isalpha(str[i]) == true) {
            result += tolower(str[i]); // adds char lower cased to result if it is alphabetical
        }

    } // for end

    return result;

} // def end

// Function 2:
// Pre-Conditions: takes in a string and a character
// Post-Conditions: returns the count of a letter in a string
int letterCount(string str, char let) {

    int count(0); // creates count variable and intializes to zero
    int size = str.length();

    for (int i = 0; i < size; i++) {
        
        if (str[i] == let) {
            count += 1; // one is added to count when there is a multiple of the same letter
        }

    } // for end

    return count;

} // def end

// Function 3:
// Pre-Conditions: takes in two strings
// Post-Conditions: compares the letter count between each string
void compareStrings(string str1, string str2) {

    if (str1.empty() && str2.empty()) { // if one of the unformatted strings are empty
        cout << "The strings are not anagrams." << endl; // outputs that they are anagrams
        return; // ends function
    }

    str1 = unformatString(str1); // unformats str1 and reassigns it to str1
    str2 = unformatString(str2); // unformats str2 and reassigns it to str2
    int size1 = str1.length(), size2 = str2.length(); // takes sizes of the unformatted strings

    bool anagrams = true; // creates bool variable to control output

    for (int i = 0; i < size1; i++) { // iterates over str1
        
        char c = str1[i]; // for every letter in str1 it compares its count to every letter in str2

        if (letterCount(str1, c) != letterCount(str2, c)) { // if the count is not the same for a letter
            anagrams = false; // bool value set to false
            break; // and for loop ends prematurely
        }

    } // for end

   /* for (int i = 0; i < size2; i++) { // iterates over str2

        char c = str2[i]; // for every letter in str2 it compares its count to every letter in str1

        if (letterCount(str2, c) != letterCount(str1, c)) { // if the count is not the same for a letter
            anagrams = false; // bool value set to false
            break; // and for loop ends prematurely
        }

    } // for end */
    
    if (anagrams) { // if bool value stays true
        cout << "The strings are anagrams." << endl; // outputs that the strings are anagrams
    }
    else { // if not 
        cout << "The strings are not anagrams." << endl; // outputs that they are not anagrams
    }

    return;

} // def end
