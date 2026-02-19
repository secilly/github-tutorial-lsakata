// Lily Sakata
// A424161
// palindrome.cpp

#include <iostream> // for cout, cin, endl
#include <string>   // for string
using namespace std;
#include "pheaders.h"
#include "pfunctions.cpp"

int main() {

    // get user input
    string input;
    cout << "Enter sentence:" << endl;
    getline(cin, input);

    // clean user input
    cleanUp(input);

    // check if string is a palindrome
    if (isPalindrome(input)) {
        cout << "It is a palindrome." << endl;
    }
    else {
        cout << "It is not a palindrome." << endl;
    }

    return 0;

} // main end
