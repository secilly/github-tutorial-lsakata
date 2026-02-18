// Lily Sakata
// A424161
// vertical.cpp

#include <iostream>
using namespace std;

// Declare printV() here
void printV (long int n);

int main() {

    long int numInput;
    cout << "Enter Integer: ";
    cin >> numInput;

    // check user input
    if (numInput < 0) {
        cout << "Input must be a positive integer." << endl;
        return 0;
    }

    printV(numInput);

    return 0;
}

// Define printV() here
// Pre-Condition: takes in an integer from user input
// Post-Condition: recursively prints out each digit on its own line
void printV(long int n) {

    if (n < 10) { // base case
        cout << n << endl;
    }
    else {
        printV(n/10); // recursion
        cout << n % 10 << endl;
    }

} // def end
