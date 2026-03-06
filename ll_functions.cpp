// Lily Sakata
// A424161
// ll_functions.cpp

// Function Definitions
// Pre-Condition: takes in the start of a linked node list and two data values 
// Post-Condition: inserts a node at the end of a linked list
void h_insert(LinkNodePtr& head, string nom, int num) {
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode;

    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = nullptr; 

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = tmp_ptr;
    }
    // If the list is not empty, traverse to the last node
    else {
        LinkNodePtr current = head;
        while (current->link != nullptr) {
            current = current->link;
        } // while end

        // Change the pointer of the last node to the new node
        current->link = tmp_ptr;
    }
    
} // def end

// Pre-Condition: takes in the head of a linked list
// Post-Conditions: asks user for node values and adds them to the end of the linked list until user quits
//                  uses function h_insert
void createLL(LinkNodePtr& h) {

    string nom = "";
    int num;  
    while (true) {
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;
        if (nom == "0" && num == 0) {
            break;
        }
        h_insert(h, nom, num);
    } // while end

    if (h == nullptr) {
        cout << "This list is empty." << endl;
    }

} // def end

// Pre-Condition: takes in the head of a linked list
// Post-Condition: iterates over the linked list printing out each nodes' values
void printLL(LinkNodePtr h) {

    // doesn't print anything if list is empty
    if (h == nullptr) {
        return;
    }

    cout << "Printing the list:" << endl; 
    int count(0);
    for (LinkNodePtr iter = h; iter != nullptr; iter = iter->link) {
        cout << "Node #" << count << ": "
            << iter->name << ", "
            << iter->number << endl;
        count++;
    } // for end

    cout << "--------" << endl;

} // def end

// Pre-Condition: takes in the head of a linked list
// Post-Condition: asks user for node position and node values inserts the new node after the position
void insertNodeAfter(LinkNodePtr& h) {

    // checks if list is empty
    if (h == nullptr) {
        cout << "Cannot insert in a non-existing link." << endl;
        cout << "This list is empty." << endl;
        return;
    }

    int nodenum, num, count(0);
    string name;
    LinkNodePtr current = h;

    cout << "Enter node position to insert new node after (enter negative number to exit): ";
    cin >> nodenum;

    // checks if user quits
    if (nodenum < 0) { 
        return;
    }
    
    while (current != nullptr && count < nodenum) {
        current = current->link;
        count++;
    }

    // checks if current position is legal
    if (current == nullptr) {
        cout << "Position entered is illegal. Nothing inserted." << endl;
        return;
    }

    // get new node data
    cout << "Enter data (name, then number): ";
    cin >> name >> num;

    // create new node
    LinkNodePtr newNode = new LinkNode;
    newNode->name = name;
    newNode->number = num;

    // insert node
    newNode->link = current->link;
    current->link = newNode;
    
} // def end

// Pre-Condition: takes in the head of a linked list
// Post-Condition: finds the maximum number in the linked list
void findMax(LinkNodePtr h) {

    // checks if list is empty
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }

    int max = h->number; // initializes max as first number in linked list
    for (LinkNodePtr iter = h; iter != nullptr; iter = iter->link) {
        if (iter->number > max) { // compares next node value to current max
            max = iter->number;
        }
    } // for end

    cout << "Largest number in the list is: " << max << endl;

} // def end

// Pre-Condition: takes in the head of a linked list
// Post-Condition: finds the minimum number in the linked list
void findMin(LinkNodePtr h) {

    // checks if list is empty
    if (h == nullptr) {
        cout << "This list is empty." << endl;
        return;
    }

    int min = h->number; // initializes min as first number in linked list
    for (LinkNodePtr iter = h; iter != nullptr; iter = iter->link) {
        if (iter->number < min) { // compares next node value to current min
            min = iter->number;
        }
    } // for end

    cout << "Smallest number in the list is: " << min << endl;

} // def end