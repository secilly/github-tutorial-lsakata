// Lily Sakata
// A424161
// pfunctions.cpp

#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

#include "pheaders.h"

// Function Definitions
// Pre-Condition: takes in a cleaned string 
// Post-Condition: returns true if string is a palindrome
bool isPalindrome(string s) {

    int size = s.size();
    if (size <= 1) { // base case
        return true;
    }

    // recursion case
    if (s[0] != s[size - 1]) { // if first and last indices do not match
        return false;
    }

    // function called excluding first and last indice
    return isPalindrome(s.substr(1, size - 2));

} // def end

// Pre-Condition: takes in a string by reference
// Post-Condition: removes any characters not alphabetic from string
void cleanUp(string &s) { 

    string cleaned = "";

    // adds letter in lower case to new cleaned string
    for (char c : s) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    } // for end

    // s becomes new cleaned string
    s = cleaned;

} // def end
