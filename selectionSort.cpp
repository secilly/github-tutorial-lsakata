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
    ifstream numInput;
    cout << "Enter filename: ";
    cin >> numFile;
    numInput.open(numFile);

    // check filename
    if(numInput.fail()) {
        cerr << "Cannot open " << numFile << endl;
        exit(1);
    }

    numInput.close(); // close file
    
    // get size of input file
    int size = getFileSize(numInput, numFile);

    // create array of data
    int* array = new int[size];
    getArray(numInput, numFile, array, size);

    // print original array
    cout << "Original array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    } // for end
    cout << endl;

    // ask user for sorting method
    int choice;
    cout << "Ascending (0) or Descending (1): ";
    cin >> choice;

    bool desc = choice;

    // run sorting 
    int number_used = size, index(0);
    sort(desc, array, number_used, index);

    // print sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    } // for end

    cout << endl;

    delete [] array;
    return 0;

} // main end
