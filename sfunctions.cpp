// Lily Sakata
// A424161
// sfunctions.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
#include "sheaders.h"

// Function Definitions

// Pre-Condition: takes in two integers by reference
// Post-Condition: swaps the values of the integers
void swap_values(int& v1, int& v2) {
    int temp = v1;
    v1 = v2;
    v2 = temp;
} // def end

// Pre-Conditions: takes sorting order, array, and two integer bounds
// Post-Condition: returns the index of the smallest or largest number (depending on sorting order)
int find_index_of_swap(bool desc, int a[], int start_index, int number_used) {

    int target_index = start_index;

    for (int i = start_index + 1; i < number_used; i++) {
        if (desc) {
            if (a[i] > a[target_index]) 
                target_index = i; // Find largest for descending
        } 
        else {
            if (a[i] < a[target_index]) 
                target_index = i; // Find smallest for ascending
        }
    } // for end

    return target_index;

} // def end

// Pre-Condition: takes in bool for sorting method, int array, and integer bounds
// Post-Condition: prints out sorted array once finished selection sorting
void sort(bool desc, int a[], int number_used, int index) {

    if (index >= number_used - 1) {
        for (int i = 0; i < number_used; i++) {
            cout << a[i];
            if (i < number_used - 1) {
                cout << " ";
            }
        } // for end
        cout << endl;
        return;
    }

    int swap_idx = find_index_of_swap(desc, a, index, number_used);
    swap_values(a[index], a[swap_idx]);
    sort(desc, a, number_used, index+1);

} // def end

// Pre-Condition: takes in an ifstream object and string
// Post-Condition: returns an integer representing the size of the file
int getFileSize(ifstream& inf, string fname) {
    
    inf.open(fname); // open file
    int next, count(0);

    while (inf >> next) {
        count++; // count indices
    } // while end

    inf.close(); // close file
    return count;

} // def end

// Pre-Condition: takes in an ifstream object, string, integer array and integer size
// Post-Condition: returns an integer array of the data from ifstream object
void getArray(ifstream& in, string fname, int arr[], int size) {

    in.open(fname);
    int next, i(0);

    while (in >> next) {
        arr[i] = next;
        i++;
    } // while end

    size = i; // size of data input matches with number of indices of array
    
    in.close();
    
} // def end
