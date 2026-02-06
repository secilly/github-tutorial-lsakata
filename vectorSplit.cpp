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
    
    // Prints vector components with double quotes and commas separating them
    int rsize = result.size();
    cout << "size: " << rsize << endl;
    if (rsize > 1) {
        cout << "The substrings are: ";
  
            for (int i = 0; i < rsize; i++) {
  
            cout << "\"" << result[i] << "\"";
   
            if (i < rsize - 1) {
            cout << ", ";
            }

        } // for end
    }
    else {
        cout << "The substring is: " << "\"" << result[0] << "\"";
    }

    cout << endl; // ends with new line

    return 0;
}

// FUNCTION DEFINITIONS

// Pre-Condition: takes in two strings 
// Post-Condition:
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

    return result;

} // def end
