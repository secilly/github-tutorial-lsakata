// IMPORTANT NOTE TO USER: 
// The only parts of the program that you should change are:
// 1. The function definitions that are currently on lines 30-32.
// 2. The addition of more test cases in the main() function.
// PLEASE LEAVE ALL OTHER CODE (especially the ASSERT_EQUAL() functions) AS-IS!
//
#include <iostream>
#include <cstdlib> 
#include <cmath>
#include <string>
#include <vector>
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)

using namespace std;

// FYI, templates are a way to make a variable type "flexible".
// We'll cover these at some point, but for now just leave these alone.
template <typename T>
void ASSERT_EQUAL(T, T);

template <typename T>
void ASSERT_EQUAL(const vector<T>&, const vector<T>&);

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE IN THE TESTS (do not remove):
vector<string> split(string target, string delimiter);
int bin2d(string binstring);
string dec2bh(string sdec, char bh);

// THE FOLLOWING DEFINITIONS FOR THE 3 FUNCTIONS ARE STUBS.
// REMOVE THEM AND THEN COPY YOUR OWN 3 FUNCTION DEFINITIONS:

// Pre-Condition: takes in two strings 
// Post-Condition: returns a string vector with the target string split with the specified delimiter
vector<string> split(string target, string delimiter) {
    
    vector<string> result;
    int size = target.length(), position = 0;
    
    bool nosubstring = true;
    for (int i = 0; i < size; i++) {
        if (target[i] == delimiter[0]) {
            nosubstring = false;
        }
    } // for end

    if (nosubstring == true) {
        result.push_back(target);
        return result;
    }
    
    while ((position = target.find(delimiter)) != string::npos) {

        string substring = target.substr(0, position);
        if (!substring.empty()) {
            result.push_back(substring);
        }
        target.erase(0, position + delimiter.length());

    } // while end

    result.push_back(target);
    return result;

} // def end

int bin2d(string binstring) {

    int size = binstring.length(), sum(0), p(0);
    
    for (int i = size - 1; i >= 0; i--) {
        int num = binstring[i] - '0';
        sum += (num * pow(2, p));
        p++;
    } // for end

    return sum;

} // def end

string dec2bh(string sdec, char bh) {
    
    string result;
    int denom; 
    int dec = atoi(sdec.c_str()); // convert sdec into int
    // assigns denom value based on char bh input
    if (bh == 'b') {
        denom = 2;
    }
    else if (bh == 'h') {
        denom = 16;
    }
    
    while (dec > 0) {
        int remain = dec % denom;
        char currentDigit;
        if (remain < 10) {
            currentDigit = (remain + '0');
        } 
        else {
            currentDigit = (remain - 10 + 'A'); // For Hex A-F
        }
        result = currentDigit + result;
        dec /= denom;
        
    } // while end

    return result;

} // def end


int main() {
    cout << "Testing split..." << endl;    
    vector<string> answer;

    // Testing split function
    answer = {"Apples", "Bananas", "Cherries", "Dragon Fruits", "Elderberries"};
    ASSERT_EQUAL(answer, split("Apples,Bananas,Cherries,Dragon Fruits,Elderberries", ","));

    answer = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    ASSERT_EQUAL(answer, split("The quick brown fox jumps over the lazy dog", " "));

    answer = {"It w", "s r", "re, I w", "s there."};
    ASSERT_EQUAL(answer, split("It was rare, I was there.", "a"));

    answer = {"Can you hear me?", " - The Machine"};
    ASSERT_EQUAL(answer, split("\"Can you hear me?\" - The Machine", "\""));


    // Feel free to add additional test cases and edge cases
    // answer = {}
    // ASSERT_EQUAL(answer, split("", ""));


    cout << endl << "Testing bin2d..." << endl;
    // Testing binary to decimal
    ASSERT_EQUAL(0, bin2d("0"));
    ASSERT_EQUAL(2, bin2d("10"));
    ASSERT_EQUAL(9,bin2d("1001"));
    ASSERT_EQUAL(45,bin2d("101101"));
    ASSERT_EQUAL(246, bin2d("11110110"));

    cout << "Testing dec2hb..." << endl;
    // Testing decimal to binary
    ASSERT_EQUAL(string("1010"), dec2bh("10", 'b'));
    ASSERT_EQUAL(string("1111"), dec2bh("15", 'b'));
    ASSERT_EQUAL(string("1100100"), dec2bh("100", 'b'));

    // Testing decimal to hex conversion
    ASSERT_EQUAL(string("A"), dec2bh("10", 'h'));
    ASSERT_EQUAL(string("64"), dec2bh("100", 'h')); 

    // Feel free to add additional test cases and edge cases
    // ASSERT_EQUAL(string("64"), dec2bh("100", 'h')); 


    return 0;
}


// Template function to compare expected and actual values.
// If the values match, it prints a "PASSED" message; otherwise, a "FAILED" message.
template <typename T>
void ASSERT_EQUAL(T expected, T actual) {
    if (expected == actual) {
        cout << "PASSED: Expected and actual values are equal: " << expected << endl;
    } else {
        cout << "FAILED: Expected " << expected << " but got " << actual << endl;
    }
}

template <typename T>
void ASSERT_EQUAL(const vector<T>& expectation, const vector<T>& actuality) {
    T expect;
    T actual;
    if (expectation.size() != actuality.size()) {
	    cout << "FAILED: Expected vector of size " << expectation.size() << " but got " << actuality.size() << endl;
	    return;
    }
    for (size_t i = 0; i < min(expectation.size(), actuality.size()); i++) {
	    expect = expectation[i];
	    actual = actuality[i];
    	if (expect == actual) continue;
        cout << "FAILED: With index=" << i << ", Expected " << endl << "\t\"" << expect << "\"\n" << "\tbut got " << endl << "\t\"" << actual << "\"\n";
	    return;
    }

    cout << "PASSED: Expected and actual values are equal:";
    for (const T& expect: expectation) cout << endl << "\t" << expect;
    cout << endl << endl;    
}

