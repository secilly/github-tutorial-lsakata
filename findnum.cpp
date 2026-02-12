#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
int FindNum(ifstream &ifs);

int main() {
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    // find the 2nd largest int and print it
    cout << FindNum(ifs) << endl;
    
    ifs.close();
    return 0;
} // main end

// DEFINE FUNCTION HERE. 
// Pre-Condition: given ifstream object
// Post-Condition: returns second largest integer from given input file
int FindNum (ifstream &ifs) {
    
    vector<int> nums = {};
    int num, size(0);

    while (ifs >> num) {
        nums.push_back(num);
        size++;
    } // while end

    // find maximum value in vector
    int max = nums[0];
    for (int i = 1; i < size; i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    } // for end

    // find the second greatest number in vector
    int secondMax = nums[0];
    for (int i = 1; i < size; i++) {
        if (secondMax < nums[i] && nums[i] < max) {
            secondMax = nums[i];;
        }
    } // for end
    
    return secondMax;

} // def end
