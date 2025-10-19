//class to store all parameters of amazon product
#include <string>
#include <iostream>
using namespace std;

//only need item id, name, and category
//all other data items don't matter in this context
//categories are a linked list -> some products have multiple

//productData class definition at very bottom (requires llist def first)


class itemCategory{
public:
    string data;     // Data stored in the node
    itemCategory* next;   // Pointer to the next node in the list

    // Constructor to initialize a new node
    itemCategory(string val) : data(val), next(nullptr) {}
};

class categoryList {
private:
    itemCategory* head; // Pointer to the first node in the list

public:
    // Constructor
    categoryList() : head(nullptr) {}

    // Destructor to free memory
    ~categoryList() {
        itemCategory* current = head;
        while (current != nullptr) {
            itemCategory* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr; // Ensure head is null after deletion
    }

    // Method to add a new node to the front of the list
    void addFront(string val) {
        itemCategory* newNode = new itemCategory(val);
        newNode->next = head;
        head = newNode;
    }

    // Method to add a new node to the end of the list
    void addBack(string val) {
        itemCategory* newNode = new itemCategory(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        itemCategory* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Method to display the linked list
    void display() const {
        itemCategory* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Method to remove the first node
    void removeFront() {
        if (head == nullptr) {
            return; // List is empty
        }
        itemCategory* temp = head;
        head = head->next;
        delete temp;
    }

    // Method to remove a specific node by value (first occurrence)
    void remove(string val) {
        if (head == nullptr) {
            return;
        }
        if (head->data == val) {
            removeFront();
            return;
        }
        itemCategory* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }
        if (current->next != nullptr) { // Found the node to remove
            itemCategory* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
};

class productData{

private: 
int itemID;
string productName;
categoryList itemCategories; //needs to be a linked list :(

public: 
productData() : itemID(0), productName("") {}

};
