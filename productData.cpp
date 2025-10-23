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

    // Copy constructor (deep copy)
    categoryList(const categoryList& other) : head(nullptr) {
        if (other.head == nullptr)
            return;

        head = new itemCategory(other.head->data);
        itemCategory* current = head;
        itemCategory* otherCurrent = other.head->next;

    while (otherCurrent != nullptr) {
            current->next = new itemCategory(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }


    categoryList& operator=(const categoryList& other) {
    if (this == &other)
        return *this;

    // Delete current list
    while (head != nullptr) {
        itemCategory* temp = head;
        head = head->next;
        delete temp;
    }

    // Deep copy from other
    if (other.head == nullptr)
        return *this;

    head = new itemCategory(other.head->data);
    itemCategory* current = head;
    itemCategory* otherCurrent = other.head->next;

    while (otherCurrent != nullptr) {
        current->next = new itemCategory(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }

    return *this;
}

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
string itemID;
string productName;
categoryList itemCategories; //needs to be a linked list :(

public: 
productData() : itemID(""), productName("") {}

productData(string item, string name, categoryList list):
    itemID(item), productName(name), itemCategories(list){}

//public interface getters to print after searching
string getName(){
    return this->productName;
}
string getID(){
    return this->itemID;
}

void printCategories(){ //display categories
    itemCategories.display();
}

};
