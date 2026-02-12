#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
vector<int> SeqSearchAll (int target, ifstream &ifs);

int main() {
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> returned = SeqSearchAll (target, ifs);
    ifs.close();

    if (returned[0] == -1)
        cout << "Target not found!\n";
    else {
        cout << "Target found at position(s): ";
        for (int i = 0; i < returned.size(); i++) {
            cout << returned[i] << " ";
        } // for
        cout << endl;
    } // else
    return 0;
} // main end

// DEFINE FUNCTION HERE. 
// Pre-Condition: given ifstream object
// Post-Condition: returns vector of integers of the target indices or -1
vector<int> SeqSearchAll (int target, ifstream &ifs) {
    
    int i(0), num;
    vector<int> indexes = {};

    while (ifs >> num) {
        if (num == target)
            indexes.push_back(i);

        i++;
    } // while end

    if (indexes.empty()) {
        indexes.push_back(-1);
    }

    return indexes;

} // def end
