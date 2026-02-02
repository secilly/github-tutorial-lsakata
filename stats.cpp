#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
using namespace std;

typedef int* IntPtr;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main() {
    // Sets the printing of floating-point numbers
    // to show only 2 places after the decimal point
    cout << fixed << showpoint;
    cout << setprecision(2);

    // MISSING CODE HERE (you can remove these comments)
    int size;

    cout << "Enter number of grades: ";

    cin >> size;
    
    if (size < 1) {
        cerr << "Error!\n";
        exit(1);
    }

    IntPtr array = new int[size];

    cout << "Enter grades (each on new line):" << endl;

    for (int i = 0; i < size; i++) {
        cin >> array[i];
    } // for end

    bubbleSort(array, size);
    
    double avg = average(array, size);
    double med = median(array, size);
    double std = stddev(array, size);

    cout << "Here are some statistics:" << endl;
    cout << setw(9) << "Average: " << avg << endl;
    cout << setw(9) << "Median: " << med << endl;
    cout << setw(9) << "StdDev: " << std << endl;

    delete [] array;

    return 0;

} // main end

// This is bubbleSort - it is given for you to use.
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
}

// FUNCTION DEFINITIONS

// Function 1:
// Pre-Condition: takes in a dynamic int array and its size
// Post-Condition: returns the average of the indices 
double average (int *array, int size) {

    double sum (0), average;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    } // for end

    return average = sum/size;

} // def end


// Function 2:
// Pre-Condition: takes in a dynamic int array and its size
// Post-Condition: returns the median of the array 
double median(int *array, int size) {
    
    int i = (size/2);

    if (size % 2 != 0) {
        double median = array[i];
        return median;
    }
    else {
        double sum = array[i - 1] + array[i];
        double median = sum/2;
        return median;
    }

} // def end

// Function 3:
// Pre-Condition: takes in a dynamic int array and its size
// Post-Condition: returns the standard deviation of the array
double stddev(int* array, int size) {

    double sum(0);
    double avg = average(array, size);

    for (int i = 0; i < size; i++) {
        sum += pow((array[i] - avg), 2.0);
    } // for end
    
    double fraction = sum / (size - 1);

    double std = pow(fraction, 0.5);
    return std;

} // def end
