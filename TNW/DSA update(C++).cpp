#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char fname[50];
    char lname[50];
    int age;
    int ID;
    float cgpa;
    char dep[50];
};

struct Node {
    Student data;
    Node *next;
};

// Common Functions
Student createStudent() {
    Student s;
    cout << "First name: "; cin >> s.fname;
    cout << "Last name: "; cin >> s.lname;
    cout << "Age: "; cin >> s.age;
    cout << "ID: "; cin >> s.ID;
    cout << "CGPA: "; cin >> s.cgpa;
    cout << "Department: "; cin >> s.dep;
    return s;
}

// Linked List Operations
Node *createNode(Student s) {
    Node   *newNode = new Node;
    newNode->data = s;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, Student s) {
    Node* newNode = createNode(s);
    newNode->next = head;
    head = newNode;
    cout << "Inserted at beginning!\n";
}

void insertAtEnd(Node*& head, Student s) {
    Node* newNode = createNode(s);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted at end!\n";
}

void insertAtPosition(Node*& head, Student s, int pos) {
    if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }
    if (pos == 1) {
        insertAtBeginning(head, s);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;

    if (!temp) {
        cout << "Position out of range!\n";
        return;
    }

    Node* newNode = createNode(s);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted at position " << pos << "!\n";
}

void deleteFromBeginning(Node*& head) {
    if (!head) {
        cout << "List empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Deleted from beginning!\n";
}

void deleteFromEnd(Node*& head) {
    if (!head) {
        cout << "List empty!\n";
        return;
    } 
  else  if (!head->next) {
        delete head;
        head = nullptr;
        cout << "Deleted from end!\n";
        return;
    }  else

    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    cout << "Deleted from end!\n";
}

void deleteFromPosition(Node*& head, int pos) {
   
    if (!head) {
        cout << "List empty!\n";
        return;
    }
    else if (pos < 1) {
        cout << "Invalid position!\n";
        return;
    }
    else if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = head, *prev = nullptr;
    for (int i = 1; temp && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

   else  if (!temp) {
        cout << "Position out of range!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Deleted from position " << pos << "!\n";
}

// Linked List Sorting
void bubbleSortID(Node* head) {
    bool swapped;
    Node* ptr;
    Node* lptr = nullptr;
    do {
        swapped = false;
        ptr = head;
        while (ptr->next != lptr) {
            if (ptr->data.ID > ptr->next->data.ID) {
                swap(ptr->data, ptr->next->data);
                swapped = true;    
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
    cout << "Sorted by ID (Bubble Sort)!\n";
}

void selectionSortFname(Node* head) {
    for (Node *i = head; i; i = i->next) {
        Node* min = i;
        for (Node *j = i->next; j; j = j->next)
            if (strcmp(j->data.fname, min->data.fname) < 0)
                min = j;
        swap(i->data, min->data);
    }
    cout << "Sorted by Name (Selection Sort)!\n";
}

// Linked List Searching
void linearSearchID(Node* head, int id) {
    bool found = false;
    while (head) {
        if (head->data.ID == id) {
            cout << "Found: " << head->data.fname << " (ID: " << id << ")\n";
            found = true;
        }
        head = head->next;
    }
    if (!found) cout << "ID not found!\n";
}

void linearSearchFname(Node* head, char* fname) {
    bool found = false;
    while (head) {
        if (strcmp(head->data.fname, fname) == 0) {
            cout << "Found: " << head->data.ID << " (" << fname << ")\n";
            found = true;
        }
        head = head->next;
    }
    if (!found) cout << "Name not found!\n";
}

// Array Operations
void insertAtBeginning(Student arr[], int& size, int capacity, Student s) {
    if (size >= capacity) {
        cout << "Array is full!\n";
        return;
    }
    for (int i = size; i > 0; i--) 
  arr[i] = arr[i - 1];
    arr[0] = s;
    size++;
    cout << "Inserted at beginning!\n";
}

void insertAtEnd(Student arr[], int& size, int capacity, Student s) {
    if (size >= capacity) {
        cout << "Array is full!\n";
        return;
    }
    arr[size++] = s;
    cout << "Inserted at end!\n";
}

void insertAtPosition(Student arr[], int& size, int capacity, Student s, int pos) {
    if (size >= capacity) {
        cout << "Array is full!\n";
        return;
    }
    if (pos < 0  pos > size) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = size; i > pos; i--) 
  arr[i] = arr[i - 1];
    arr[pos] = s;
    size++;
    cout << "Inserted at position " << pos << "!\n";
}

void deleteFromBeginning(Student arr[], int& size) {
    if (size == 0) {
        cout << "Array empty!\n";
        return;
    }
    for (int i = 0; i < size - 1; i++) 
  arr[i] = arr[i + 1];
    size--;
    cout << "Deleted from beginning!\n";
}

void deleteFromEnd(int& size) {
    if (size == 0) {
        cout << "Array empty!\n";
        return;
    }
    size--;
    cout << "Deleted from end!\n";
}

void deleteFromPosition(Student arr[], int& size, int pos) {
    if (size == 0) {
        cout << "Array empty!\n";
        return;
    }
    if (pos < 0  pos >= size) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < size - 1; i++) arr[i] = arr[i + 1];
    size--;
    cout << "Deleted from position " << pos << "!\n";
}

// Array Sorting
void bubbleSortID(Student arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j].ID > arr[j + 1].ID)
                swap(arr[j], arr[j + 1]);
    cout << "Sorted by ID (Bubble Sort)!\n";
}

void selectionSortFname(Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (strcmp(arr[j].fname, arr[min].fname) < 0)
                min = j;
        swap(arr[i], arr[min]);
    }
    cout << "Sorted by Name (Selection Sort)!\n";
}

// Array Searching
void linearSearchID(Student arr[], int size, int id) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].ID == id) {
            cout << "Found at index " << i << " (ID: " << id << ")\n";
            found = true;
        }
    }
    if (!found) cout << "ID not found!\n";
}

void linearSearchFname(Student arr[], int size, char* fname) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].fname, fname) == 0) {
            cout << "Found at index " << i << " (" << fname << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Name not found!\n";
}

// Display Functions
void displayList(Node* head) {
    if (!head) {
        cout << "List empty!\n";
        return;
    }
    cout << "\nLinked List:\n";
    while (head) {
        cout << "Name: " << head->data.fname << " " << head->data.lname
             << " | ID: " << head->data.ID << " | CGPA: " << head->data.cgpa << endl;
        head = head->next;
    }
}

void displayArray(Student arr[], int size) {
    if (size == 0) {
        cout << "Array empty!\n";
        return;
    }
    cout << "\nArray:\n";
    for (int i = 0; i < size; i++) {
        cout << "Name: " << arr[i].fname << " " << arr[i].lname
             << " | ID: " << arr[i].ID << " | CGPA: " << arr[i].cgpa << endl;
    }
}

int main() {
    Node* head = nullptr;
    Student* arr = nullptr;
    int arrSize = 0, arrCapacity = 0;
    
    int choice, subChoice, pos, id;
    char fname[50];
    Student s;

    while (true) {
        cout << "\nMain Menu\n1. Linked List\n2. Array\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 3) break;

        switch (choice) {
            case 1: // Linked List operations
                while (true) {
                    cout << "\nLinked List Menu\n1. Insert\n2. Delete\n3. Sort\n4. Search\n5. Display\n6. Back\nChoice: ";
                    cin >> subChoice;
                    if (subChoice == 6) break;

                    switch (subChoice) {
                        case 1: {
                            cout << "1. Beginning\n2. End\n3. Position\nChoice: ";
                            cin >> subChoice;
                            s = createStudent();
                            if (subChoice == 1) insertAtBeginning(head, s);
                            else if (subChoice == 2) insertAtEnd(head, s);
                            else {
                                cout << "Position: ";
                                cin >> pos;
                                insertAtPosition(head, s, pos);
                            }
                            break;
                        }
                        case 2: {
                            cout << "1. Beginning\n2. End\n3. Position\nChoice: ";
                            cin >> subChoice;
                            if (subChoice == 1) deleteFromBeginning(head);
                            else if (subChoice == 2) deleteFromEnd(head);
                            else {
                                cout << "Position: ";
                                cin >> pos;
                                deleteFromPosition(head, pos);
                            }
                            break;
                        }
                        case 3: {
                            cout << "1. Bubble Sort (ID)\n2. Selection Sort (Name)\nChoice: ";
                            cin >> subChoice;
                            if (subChoice == 1) bubbleSortID(head);
                            else selectionSortFname(head);
                            break;
                        }
                        case 4: {
                            cout << "1. Search by ID\n2. Search by Name\nChoice: ";
                            cin >> subChoice;
                            if (subChoice == 1) {
                                cout << "Enter ID: ";
                                cin >> id;
                                linearSearchID(head, id);
                            } else {
                                cout << "Enter name: ";
                                cin >> fname;
                                linearSearchFname(head, fname);
                            }
                            break;
                        }
                        case 5:
                            displayList(head);
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;

            case 2: // Array operations
                if (arr == nullptr) {
                    cout << "Enter array capacity: ";
                    cin >> arrCapacity;
                    arr = new Student[arrCapacity];
                }
                
                while (true) {
                    cout << "\nArray Menu\n1. Insert\n2. Delete\n3. Sort\n4. Search\n5. Display\n6. Back\nChoice: ";
                    cin >> subChoice;
                    if (subChoice == 6) break;

switch (subChoice) {
                        case 1: {
                            cout << "1. Beginning\n2. End\n3. Position\nChoice: ";
                            cin >> subChoice;
                            s = createStudent();
                            if (subChoice == 1) insertAtBeginning(arr, arrSize, arrCapacity, s);
                            else if (subChoice == 2) insertAtEnd(arr, arrSize, arrCapacity, s);
                            else {
                                cout << "Position: ";
                                cin >> pos;
                                insertAtPosition(arr, arrSize, arrCapacity, s, pos);
                            }
                            break;
                        }
                        case 2: {
                            cout << "1. Beginning\n2. End\n3. Position\nChoice: ";
                            cin >> subChoice;
                            if (subChoice == 1) deleteFromBeginning(arr, arrSize);
                            else if (subChoice == 2) deleteFromEnd(arrSize);
                            else {
                                cout << "Position: ";
                                cin >> pos;
                                deleteFromPosition(arr, arrSize, pos);
                            }
                            break;
                        }
                        case 3: {
                            cout << "1. Bubble Sort (ID)\n2. Selection Sort (Name)\nChoice: ";
                            cin >> subChoice;
                            if (subChoice == 1) bubbleSortID(arr, arrSize);
                            else selectionSortFname(arr, arrSize);
                            break;
                        }
                        case 4: {
                            cout << "1. Search by ID\n2. Search by Name\nChoice: ";
                            cin >> subChoice;
                            if (subChoice == 1) {
                                cout << "Enter ID: ";
                                cin >> id;
                                linearSearchID(arr, arrSize, id);
                            } else {
                                cout << "Enter name: ";
                                cin >> fname;
                                linearSearchFname(arr, arrSize, fname);
                            }
                            break;
                        }
                        case 5:
                            displayArray(arr, arrSize);
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;
        }
    }
    
    // Cleanup
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    if (arr != nullptr) delete[] arr;
    
    return 0;
}