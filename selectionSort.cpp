// Lily Sakata
// A424161
// selectionSort.cpp

#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
using namespace std;
#include "sheaders.h"
#include "sfunctions.cpp"

int main() {

    // get filename from user 
    string numFile;
    istream numInput;
    cout << "Enter filename: ";
    cin >> numFile;
    numInput.open(numFile);

    // check filename
    if(numInput.fail()) {
        cerr << "Cannot open " << numFile << endl;
    }

    // 
    getFileSize(numInput, numFile);

    int size(1);
    array = new int[size];
    newArray = new int nullptr;
    getArray(numInput, numFile, array[], size);

    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << " ";
        }
    }

    bool desc;
    cout << "Ascending (0) or Descending (1): ";
    cin >> desc;

    cout << "Sorted Array:" << endl;
    sort(desc, array[], number_used, index);

    return 0;
}
