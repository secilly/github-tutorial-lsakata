// Lily Sakata
// A424161
// file: headers.h for newanagrams

// Define class AString here!
// See PDF for details
class AString {
    public:
        AString(); // default constructor
        AString(string s); // constructor
        string getStringValue(); // getter
        // setter functions
        void getAString();
        void cleanUp();
        void countLetters(int arr[]);

    private:
        string StringValue;
}; // class end

bool compareCounts(int a[], int b[]); 
const int ARRAYSIZE = 26;

