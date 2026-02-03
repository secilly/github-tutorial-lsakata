// Lily Sakata
// A424161
// anagrams.cpp

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// FUNCTION DECLARATIONS
int stringSize(string str);
string unformatString(string str);
int letterCount(string str, char let);
void compareStrings(string str1, string str2);


int main()
{
    string input1, input2;
    cout << "Enter first string:" << endl;
    getline(cin, input1);
    cout << "Enter second string:" << endl;
    getline(cin, input2);

    compareStrings(input1, input2);

    return 0;
}

// FUNCTION DECLARATIONS

// Function 1:
// Pre-Conditions: takes in a string
// Post-Conditions: returns the size
int stringSize(string str) {

    int size = str.length();
    return size; // returns the size of the string input

} // def end

// Function 2:
// Pre-Conditions: takes in a string
// Post-Conditions: returns the string lowercase and only with letters (alphabetic)
string unformatString(string str) {
  
    int size = stringSize(str);

    for (int i = 0; i < size; i++) {
        
        if (isalpha(str[i]) == true) {
            str += tolower(str[i]); // adds char lower cased to str if it is alphabetical
        }

    } // for end

    return str;

} // def end

// Function 2:
// Pre-Conditions: takes in a string and a character
// Post-Conditions: returns the count of a letter in a string
int letterCount(string str, char let) {

    int count(0), size = stringSize(str); // creates count variable and gets string size
    str = unformatString(str); // unformats string

    for (int i = 0; i < size; i++) {
        
        if (str[i] == let) {
            count += 1; // one is added to count when there is multiple(s)
        }

    } // for end

    return count;

} // def end

// Function 3:
// Pre-Conditions: takes in two strings
// Post-Conditions: compares the letter count between each string
void compareStrings(string str1, string str2) {

    int size1 = stringSize(str1), size2 = stringSize(str2);
    str1 = unformatString(str1);
    str2 = unformatString(str2);
    
    if (size1 != size2) {
        cout << "The strings are not anagrams." << endl;
        return;
    }
    
    bool anagram = true;

    for (int i = 0; i < size1; i++) {
        
        char c = str1[i];

        if (letterCount(str1, c) != letterCount(str2, c)) {
            anagram = false;
            break;
        }

    } // for end

    if (anagram = true) {
        cout << "The strings are anagrams." << endl;
    }
    else {
        cout << "The strings are anagrams." << endl;
    }

} // def end
