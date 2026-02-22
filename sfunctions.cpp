// File: sfunctions.cpp
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

    int target_index;

    // find smallest number
    if ( desc ) {
        for (int i = start_index; i < number_used) {
            if (a[i] < a[i + 1]) {
                target_index = i;
            }
        } // for end
        return target_index;
    } // desc end

    // find largest number
    else { 
        for (int i = start_index; i < number_used) {
            if (a[i] > a[i + 1]) {
                target_index = i;
            } // for end
        }
        return target_index;
    } // asc end

} // def end

void sort(bool desc, int a[], int number_used, int index) {

    if (a[index] == number_used) {
        for (int i = 0; i < size; i++) {
            cout << a[i];
            if (i < size - 1) {
                cout << " ";
            }
        } // for end
    }
    else if (bool) {
        if (a[index] < number_used) {
            swap_values(a[index], number_used]);
            sort(desc, a[], number_used, index);
        }
    }
    else {
        if (a[index] > number_used) {
            swap_values(a[index], number_used);
            sort(desc, a[], number_used, index);
        }
    }

} // def end

// Pre-Condition: takes in an ifstream object and string
// Post-Condition: returns an integer representing the size of the file
int getFileSize(ifstream& inf, string fname) {
    
    inf.open(fname); // open file
    int next, count(0);

    while (inf >> next) {
        count++; // count indices
    } // while end

    inf.close(fname); // close file
    return count;

} // def end

// Pre-Condition: takes in an ifstream object, string, integer array and integer size
// Post-Condition: returns an integer array of the data from ifstream object
void getArray(ifstream& in, string fname, int arr[], int size) {

    in.open(fname);
    int next, i(0), size(1);

    while (in >> next) {
        array[i] = next;
        i++;
        
        // create new array with more space
        if (i == size) {
            newArray= new int[size + 1];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            } // for end
        }

        delete [] array;
        array = newArray;

        size++;
    
    } // while end

    size = i; // size of array matches with number of indices
    
    in.close(fname);
    
} // def end
