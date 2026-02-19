// File: pfunctions.cpp

#include <iostream>
#include <string> 
#include <cctype>
using namespace std;

#include "pheaders.h"

// Function Definitions
// Pre-Condition: takes in a cleaned string 
// Post-Condition: returns true if string is a palindrome
bool isPalindrome(string s) {
    // This MUST be written as a RECURSIVE FUNCTION! (or you get no lab credit)

    int size = s.size();
    if (size <= 1) { // base case
        return true;
    }

    if (s[0] != s[size - 1]) {
        return false;
    }

    return isPalindrome(s.substr(1, size - 2));

} // def end

// Pre-Condition: takes in a string by reference
// Post-Condition: removes any characters not alphabetic from string
void cleanUp(string &s) { 

    string cleaned = "";

    for (char c : s) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    } // for end

    s = cleaned;

} // def end
