// Lily Sakata
// A424161
// stats2.cpp

#include <iostream> // for cout and cin
#include <fstream> // for reading input
#include <cmath> // for pow()
#include <iomanip> // for setw()
#include <cstdlib> // for exit()
using namespace std;

typedef int* IntPtr;

// FUNCTION DECLARATIONS
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main () {
    
    cout << fixed << showpoint;
    cout << setprecision(2);

    string infileName;
    ifstream numberInput;
    cout << "Enter filename: ";
    cin >> infileName;
    
    numberInput.open(infileName);

    if (numberInput.fail()) {
        cerr << "Cannot open " << infileName << endl;
        exit(1);
    }

    // calculate size of array
    int next, size(1), i(0);  

    IntPtr array = new int[size];
    IntPtr newArray = nullptr;

    while (numberInput >> next) {
        
        array[i] = next;
        i++;

        // when no space left in array
        if (i == size) {
            
            // create new array with more space
            newArray = new int[size + 1];
            
            // copy old array to new array
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            } // for end 
    
            delete [] array;
            array = newArray;

            size++;
        }

    } // while end
    
    // debugging
    /*for (int i = 0; i < size; i++) {
        cout << i << ": " << array[i] << endl;
    }*/

    // get rid of last empty indice in array
    size--;

    // ends if dynamic array is empty
    if (size == 0) {
        return 0;
    }

    bubbleSort(array, size);
    double avg = average(array, size);
    double med = median(array, size);
    double std = stddev(array, size);

    cout << "Here are some statistics:" << endl;
    cout << setw(9) << "N: " << size << endl;
    cout << setw(9) << "Average: " << avg << endl;
    cout << setw(9) << "Median: " << med << endl;
    cout << setw(9) << "StdDev: " << std << endl;

    delete [] array;
    delete [] newArray;

    return 0;

} // main end

// FUNCTION DEFINTIONS
// Pre-Condition: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(int *array, int size) {
    int temp;
    for (int i = size-1; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (array[j-1] > array[j]) {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            } // if
        } // for j
    } // for i
} // def end

// Pre-Condition: takes in a dynamic int array and its size
// Post-Condition: returns the average of the indices as a double
double average (int *array, int size) {

    double sum (0), average;

    for (int i = 0; i < size; i++) {
        sum += array[i]; // sums up all of the array indices
    } // for end

    return average = sum/size; // returns the sum divided by the number of indices of the array

} // def end

// Pre-Condition: takes in a dynamic int array and its size
// Post-Condition: returns the median of the array as a double
double median(int *array, int size) {

    int i = (size/2); // creates a variable that is half the size of the array

    if (size % 2 != 0) { // if the number of indices is odd
        double median = array[i]; // returns the middle indice
        return median;
    }
    else { // if the number of indices is even
        double sum = array[i - 1] + array[i];
        double median = sum/2; // returns the sum of the two middle indices divided by two
        return median;
    }

} // def end

// Pre-Condition: takes in a dynamic int array and its size
// Post-Condition: returns the standard deviation of the array as a double
double stddev(int* array, int size) {

    double sum(0); 
    double avg = average(array, size); 

    for (int i = 0; i < size; i++) { 
        sum += pow((array[i] - avg), 2.0); // sums the indices subtracted by the avg and squared
    } // for end
    
    if (size - 1 < 2) { // if the size of the array is one
        double std = 0.00; // returns the std dev as zero
        return std;
    }
    else {
        double fraction = sum / (size - 1); 
        double std = pow(fraction, 0.5); // takes the square root of fraction 
        return std; 
    }

} // def end
