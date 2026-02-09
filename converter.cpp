#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
int bin2d(string binstring);
string dec2bh(string sdec, char bh);

int main(int argc, char *argv[]) {
    
// Checks number of args
    if (argc != 3) {
        cerr << "Usage: converter <d2b, d2h, b2d> <value>" << endl;
        exit(1);
    }
    
    // separates args to their specifications
    string mode = argv[1];
    string value = argv[2];
    
    // runs functions depending on arg inputs
    if (mode == "b2d") { // binary to decimal
        if (bin2d(value) == -1) {
            cout << "Binary value contains non-binary digits." << endl;
            return 0;
        }
        cout << "The value in decimal is: " << bin2d(value) << endl;
    }
    else if (mode == "d2b") { // decimal to binary
        cout << "The value in binary is: " << dec2bh(value, 'b') << endl;
    } 
    else if (mode == "d2h") { // decimal to hex
        cout << "The value in hexadecimal is: " << dec2bh(value, 'h') << endl;
    } 
    else { // if there are invalid args 
        cerr << "Usage: converter <d2b, d2h, b2d> <value>" << endl;
        exit(1);
    }

    return 0;
    
} // main end  

// FUNCTION DEFINITIONS

// Pre-Condition: takes in a string of binary numbers
// Post-Condition: returns an integer in decimal representing the binary input
int bin2d(string binstring) {

    int size = binstring.length(), sum(0);
    int p = 0;

    // check to see if string only contains binary numbers
    for (int i = 0; i < size; i++) {
        if (binstring[i] != '0' && binstring[i] != '1') {
            return -1;
        }
    }
    
    for (int i = size - 1; i >= 0; i--) { // starts from right to left

        int num = binstring[i] - '0';
        sum += (num * pow(2, p)); // sums up converted binary numbers
        p++; // power increment

    } // for end

    return sum;

} // def end

// Pre-Condition: takes in a string representing a decimal number and a character (either h or b)
// Post-Condition: returns either the string's hex or binary equivalent depending on char input
string dec2bh(string sdec, char bh) {
    
    string result;
    int denom; 
    int dec = atoi(sdec.c_str()); // convert sdec into int

    if (dec == 0) {
        return "0";
    }

    // assigns denom value based on char bh input
    if (bh == 'b') {
        denom = 2;
    }
    else if (bh == 'h') {
        denom = 16;
    }
    
    // conversion
    while (dec > 0) {
        
        int remain = dec % denom; // remainder
        char currentDigit;

        if (remain < 10) { 
            currentDigit = (remain + '0');
        } 
        else { // For Hex A-F (uses ASCII values)
            currentDigit = (remain - 10 + 'A'); 
        }

        // adds most recent remainder to left side of result
        result = currentDigit + result;
        dec /= denom; // quotient
        
    } // while end

    return result;

} // def end
