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

    // get size of input file
    int size = getFileSize(numInput, numFile);

    // create array of data
    array = new int[size];
    getArray(numInput, numFile, array[], size);

    // print raw data
    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << " ";
        }
    }

    // ask user for sorting method
    bool desc;
    cout << "Ascending (0) or Descending (1): ";
    cin >> desc;

    // run sorting
    sort(desc, array[], number_used, index);

    // print sorted array 
    cout << "Sorted Array:" << endl;

    return 0;
}
