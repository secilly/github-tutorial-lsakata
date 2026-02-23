// Lily Sakata
// A424161
// selectionSort.cpp

#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
using namespace std;
#include "sheaders.h"

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

    numInput.close(); // close file
    
    // get size of input file
    int size = getFileSize(numInput, numFile);

    // create array of data
    int* array = new int;
    array = new int[size];
    getArray(numInput, numFile, array, size);

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

    // run sorting and print array once finished
    int number_used = size, index(0);
    sort(desc, array, number_used, index);

    return 0;
    delete [] array;
} // main end
