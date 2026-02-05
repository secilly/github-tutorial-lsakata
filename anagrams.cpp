
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
    
    if (size < 1) { // if size entered is not valid then main is terminated 
        cerr << "Error!\n"; // after an error message
        exit(1);
    }

    IntPtr array = new int[size]; // creates dynamic pointer array called array

    cout << "Enter grades (each on new line):" << endl;

    for (int i = 0; i < size; i++) {
        cin >> array[i]; // user inputs as many elements as the size of the array
    } // for end

    bubbleSort(array, size); // sorts array
    
    double avg = average(array, size); 
    double med = median(array, size); 
    double std = stddev(array, size); 

    // formatted ouput:
    cout << "Here are some statistics:" << endl;
    cout << setw(9) << "Average: " << avg << endl;
    cout << setw(9) << "Median: " << med << endl;
    cout << setw(9) << "StdDev: " << std << endl;

    delete [] array; // delete operator used on array

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
// Post-Condition: returns the average of the indices as a double
double average (int *array, int size) {

    double sum (0), average;

    for (int i = 0; i < size; i++) {
        sum += array[i]; // sums up all of the array indices
    } // for end

    return average = sum/size; // returns the sum divided by the number of indices of the array

} // def end


// Function 2:
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

// Function 3:
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

 anagrams.cpp
 Download
// Lily Sakata
// A424161
// anagrams.cpp

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// FUNCTION DECLARATIONS

string unformatString(string str);
int letterCount(string str, char let);
void compareStrings(string str1, string str2);


int main()
{
    string input1, input2; // creates two strings
    cout << "Enter first string:" << endl;
    getline(cin, input1); // input1 is initialized as user input
    cout << "Enter second string:" << endl;
    getline(cin, input2); // input2 is initialized as user input 

    compareStrings(input1, input2); 

    return 0;

} // main end

// FUNCTION DEFINITIONS

// Function 1:
// Pre-Conditions: takes in a string
// Post-Conditions: returns the string lowercase and only with letters (alphabetic)
string unformatString(string str) {
 
    string result;
    int size = str.length();

    for (int i = 0; i < size; i++) {
        
        if (isalpha(str[i]) != 0) {
            result += tolower(str[i]); // adds char lower cased to result if it is alphabetical
        }

    } // for end

    return result;

} // def end

// Function 2:
// Pre-Conditions: takes in a string and a character
// Post-Conditions: returns the count of a letter in a string
int letterCount(string str, char let) {

    int count(0); 
    int size = str.length();

    for (int i = 0; i < size; i++) {
        
        if (str[i] == let) {
            count += 1; // one is added to count when there is a multiple of the same letter
        }

    } // for end

    return count;

} // def end

// Function 3:
// Pre-Conditions: takes in two strings
// Post-Conditions: compares the letter count between each string
void compareStrings(string str1, string str2) {

    // unformats string inputs
    str1 = unformatString(str1); 
    str2 = unformatString(str2);

    if (str1.length() != str2.length()) { // if the sizes are not equal
        cout << "The strings are not anagrams." << endl;
        return;
    }

    else {
    	for (int i = 0; i < str1.length(); i++) {
            char c = str1[i]; // if the letter count in str1 for 
            if (letterCount(str1, c) != letterCount(str2, c)) { // a letter is not the same in str2
            	cout << "The strings are not anagrams." << endl;
            	return;
            }
    	} // for end

    	cout << "The strings are anagrams." << endl;
    }

    return;

} // def end
