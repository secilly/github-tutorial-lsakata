// Lily Sakata
// A424161
// r_functions.cpp

// Function Definitions
// Pre-Condition: takes in an array of UndergradStudents and its size
// Post-Condition: sorts the array by last name
void NameSort(UndergradStudents array[], int size) {
    UndergradStudents temp; 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j-1].last_name > array[j].last_name) { // compares consecutive last names in array
                temp = array[j]; // if the ascii value is greater switches the array indices
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        } // for end j
    } // for end i
} // def end

// Pre-Condition: takes in an array of UndergradStudents and its size by reference
// Post-Condition: processes up to 20 entries and puts into an UndergradStudents array
void InitializeStructures(UndergradStudents us[], int &size) {

    for (int i = 0; i <= 19; i++) {
        if (i < 9) { // for first 9 indices
            string first_name, last_name;
            double GPA, GPA1, GPA2, GPA3, GPA4;
            // get user input
            while (first_name != 'x' || first_name != 'X') { // runs until user quits
                cout << "Student 0" << i + 1 << ":Enter first name (or x to quit): ";
                cin >> first_name;
                us[i].first_name = first_name;
                cout << "Student 0" << i + 1 << ":Enter last name: ";
                cin >> last_name; 
                us[i].last_name = last_name;
                cout << "Student 0" << i + 1 << ":Enter GPA Year 1: ";
                cin >> GPA1;
                cout << "Student 0" << i + 1 << ":Enter GPA Year 2: ";
                cin >> GPA2; 
                cout << "Student 0" << i + 1 << ":Enter GPA Year 3: ";
                cin >> GPA3; 
                cout << "Student 0" << i + 1 << ":Enter GPA Year 4: ";
                cin >> GPA4; 
                us[i].GPA = (GPA1 + GPA2 + GPA3 + GPA4) / 4; // takes average of the GPAS
            } // while end
        }
        if (i >= 9 && i <= 19) { // for tenth indice to twentieth
            string first_name, last_name;
            double GPA, GPA1, GPA2, GPA3, GPA4;
            // get user input
            while (first_name != 'x' || first_name != 'X') { // runs until user quits
                cout << "Student " << i + 1 << ":Enter first name (or x to quit): ";
                cin >> first_name;
                us[i].first_name = first_name;
                cout << "Student " << i + 1 << ":Enter last name: ";
                cin >> last_name; 
                us[i].last_name = last_name;
                cout << "Student " << i + 1 << ":Enter GPA Year 1: ";
                cin >> GPA1;
                cout << "Student " << i + 1 << ":Enter GPA Year 2: ";
                cin >> GPA2; 
                cout << "Student " << i + 1 << ":Enter GPA Year 3: ";
                cin >> GPA3; 
                cout << "Student " << i + 1 << ":Enter GPA Year 4: ";
                cin >> GPA4; 
                us[i].GPA = (GPA1 + GPA2 + GPA3 + GPA4) / 4; // takes average of the GPAS
            } // while end
        } // runs up until there are twenty indices
    } // for end
} // def end

// Pre-Condition: takes in an ofstream object, an array of UndergradStudents and its size
// Post-Condition: Prints out results in an outfile
void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
    
    outf.open(OUTPUTFILE);

    NameSort(us, size); // sorts us[]

    cout << "These are the results sorted by last name:" << endl;
    // prints out us[] that is sorted by last name
    outf << setprecision(2); // two decimal points
    for (int i = 0; i < size; i++) {
        outf << "ID# " << i + 1 << ": " 
        << us[i].first_name << ": " 
        << us[i].last_name << ": "
        << us[i].major << ": " 
        << us[i].GPA << endl;
    } // for end
    
    outf.close();

} // def end