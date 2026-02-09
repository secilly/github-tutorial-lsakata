// Lily Sakata
// A424161
// vectorSplit.cpp

#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter);

int main() {

    // Get target string from user, get delimiter string from user
    string input, delimiter;
    cout << "Enter string to split:" << endl;
    getline(cin, input);
    cout << "Enter delimiter string:" << endl;
    cin >> delimiter;

    // Call function split()
    vector<string> result = split(input, delimiter);
    
    // Prints vector string components wrapped in double quotes
    int rsize = result.size();
    
    if (rsize == 0) {
        cout << "No substrings." << endl;
    }

    else {
        cout << "The substrings are: ";
  
        for (int i = 0; i < rsize; i++) {
  
            cout << "\"" << result[i] << "\"";
   
            if (i < rsize - 1) { // comma printed up until last indice
            cout << ", ";
            }

        } // for end
    }
    
    cout << endl; // ends with new line

    return 0;

}

// FUNCTION DEFINITION
// Pre-Condition: takes in two strings (string to split and string to split by)
// Post-Condition: returns a vector of strings that were split by the delimiter
vector<string> split(string target, string delimiter) {
    
    vector<string> result;
    int size = target.length(), position = 0;
    
    bool nosubstring = true; // bool to check if delimiter exists in string
    for (int i = 0; i < size; i++) {
        if (target[i] == delimiter[0]) {
            nosubstring = false; // if the delimiter is found in target bool value changed
        }
    } // for end

    if (nosubstring == true) { // if delimiter never found in target
        result.push_back(target); // target is added to result
        return result; 
    }
    
    // runs as long as the delimiter is found in target
    while ((position = target.find(delimiter)) != string::npos) {

        string substring = target.substr(0, position);
        // empty strings are not added to result
        if (!substring.empty()) {
            result.push_back(substring);
        }
        // substring and delimiter erased from target
        target.erase(0, position + delimiter.length());

    } // while end

    // when no delimiter exists rest of target added to result
    result.push_back(target);

    return result;

} // def end
