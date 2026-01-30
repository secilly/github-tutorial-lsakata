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
    return size--;

} // def end

// Function 2:
// Pre-Conditions: takes in a string
// Post-Conditions: returns the string lowercase and only with letters
string unformatString(string str) {
  
    int size = stringSize(str);

    for (int i = 0; i < size; i++) {
        
        if (isalpha(str[i]) == false) {
            str.erase(i, 1); // removes character if not alphabetic
        }
        else {
            i++;
        }

        str[i] = tolower(str[i]); // puts char to lower case if alphabetic

    } // for end

    return str;

} // def end

// Function 2:
// Pre-Conditions: takes in a string and a character
// Post-Conditions: returns the count of a letter in a string and removes them
int letterCount(string str, char let) {

    int count(1), size = stringSize(str); // creates count variable and gets string size
    unformatString(str); // unformats string

    for (int i = 0; i < size; i++) {
        
        if (str[i] == let) {
            count += 1; // one is added to count when there is multiple(s)
            str.erase(i, 1); // removes the letter in the string
            i -= 1; // sets index back one (so it does not skip any indices)
        }

    } // for end

    return count;

} // def end

// Function 3:
// Pre-Conditions: takes in two strings
// Post-Conditions: compares the letter count between each string
void compareStrings(string str1, string str2) {

    int size1 = stringSize(str1), size2 = stringSize(str2);

    for (int i = 0; i < size1; i++) {

        int pos2 = str2.find(str1[0]);
        int count2 = letterCount(str2, str2[pos2]);
        int count1 = letterCount(str1, str1[0]);

        if (count2 != count1) {
            cout << "The strings are not anagrams." << endl;
            break;
        }
        else {
            continue;
        }
    } // for end

    cout << "The strings are anagrams." << endl;

} // def end
