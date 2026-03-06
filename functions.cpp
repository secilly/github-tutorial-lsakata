// Lily Sakata
// A424161
// file: functions.cpp for newanagrams

// constructors
AString::AString() { StringValue = ""; } // default
AString::AString(string s) { StringValue = s; }

// getter
string AString::getStringValue() { return StringValue; }

// setter functions
// Pre-Condition: asks user for a string value
// Post-Condition: sets StringValue to user input
void AString::getAString() {
    cout << "Enter string value: ";
    getline(cin, StringValue); // get user input
} // getAString end

// Pre-Condition: takes in an integer array
// Post-Condition: returns an integer array with the count of each letter with its corresponding index
void AString::countLetters(int arr[]) {
    for(unsigned char c : StringValue) {
        int i = c - 'a'; // create index
        arr[i] += 1; 
    } // for end
} // countLetters end

// Pre-Condition: takes in a string by reference
// Post-Condition: returns the string containing only lowercase letters
void AString::cleanUp() {
    string cleaned = "";
    for (unsigned char c : StringValue) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    } // for end
    StringValue = cleaned; 
} // cleanUp end

// other function
// Pre-Condition: takes in two integer arrays of constant size
// Post-Condition: returns true if the values at equal indices are the same, otherwise false
bool compareCounts(int a[], int b[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
        if (a[i] != b[i]) {
            return true;
        }
    } // for end
    return false;
} // def end
