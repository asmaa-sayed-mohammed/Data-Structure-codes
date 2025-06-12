#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class single_linked_list {
public:
    int length = 0;
    node *head;
    single_linked_list() {
        head = nullptr;
    }

    single_linked_list(single_linked_list& other) {
        copyList(other.head);
    }

    ~single_linked_list() {
        destroyList();
    };

    void insertAtEnd(int value) {
        node *newNode = new node();
        newNode->data = value;
        newNode->next = nullptr;
        // if head = null it's meaning that list is empty, so make head = node it will refer to new node
        // when he is referring to node this mean that the list isn't empty
        if (head == nullptr) {
            head = newNode;
        } else {
            // if the list isn't empty, traverse the list till you reach put the last node which next  = null
            // let next = new node this mean that node addet to the list
            node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }

    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }else {
            return false;
        }
    }

    void insertFront(int value) {
        node *newNode = new node();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
        }else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    int getLength() {
        return length;
    }

    void print() {
        if (length == 0) {
            cout << "Empty List.\n";
        }else {
            node *current = head;
            while (current != nullptr) {
                cout << current->data << ", ";
                current = current->next;
            }
        }
    }

    int front() {
        if (length == 0) {
            cout << "Empty List.\n";
        }else {
            return head->data;
        }
    }

    int back() {
        if (length == 0) {
            cout << "Empty List.\n";
        }else {
            node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            return current->data;
        }
    }

    node* begin() {
        node *current;
        if (length == 0) {
            cout << "Empty List.\n";
        }
        else {
            current = head;
        }
        return current;
    }

    node* end() {
        node *current;
        if (length == 0) {
            cout << "Empty List.\n";
        }
        else {
            current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            return current;
        }
    }

    void destroyList() {
        if (length == 0) {
            cout << "Empty List.\n";
        }else {
            node *current = head;
            while (current != nullptr) {
                node *temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
        }
        length = 0;
    }

    void copyList(node *oldHead) {
        if (oldHead == nullptr) {
            cout << "Empty List.\n";
            head = nullptr;
        }
        else {
            head = new node;
            head -> data = oldHead -> data;

            node *current = head;
            node *temp = oldHead -> next;
            while (temp != nullptr) {
                current -> next = new node;
                current = current -> next;
                current -> data = temp -> data;
                temp = temp -> next;
            }
            current -> next = nullptr;
        }
    }

    single_linked_list &operator=(single_linked_list &other) {
        if (this == &other) {
            return *this;
        }else {
            destroyList();
            copyList(other.head);
            return *this;
        }
    }

    void resetList() {
        destroyList();
    }

};

class unorderedSingleList : public single_linked_list{
    public:

    int search(int value) {
        node *current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->data == value) {
                found = true;
                break;
            }else {
                current = current->next;
            }
        }
        if (found == true) {
            cout << "Value found{\n";
            return current->data;
        }else {
            cout << "Value not found{\n";
        }
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "Empty List.\n";
        }else {
            node *current = head;
            while (current != nullptr) {
                if (current->next->data == value) {
                    node *temp = current->next;
                    current->next = current ->next -> next;
                    delete temp;
                    break;
                }else {
                    current = current->next;
                }
            }
        }
    }
};

class ordereLinkedList:public single_linked_list {
    public:

    void insertAtEnd(int value) {
        node *newNode = new node();
        newNode->data = value;
        node *current = end();
        if (current -> data < value) {
            current -> next = newNode;
            newNode -> next = nullptr;
        }else if (head -> next == nullptr) {
            head -> next = newNode;
            newNode -> next = nullptr;
        }
        else {
            cout << "Value can not be inserted here.\n";
        }
    }

    void insertFront(int value) {
        node *newNode = new node();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
        }else if (head -> data > value) {
            node *temp = head;
            head = newNode;
            newNode ->next = temp;
        }else {
            cout << "Value can't be inserted at first.\n";
        }
    }

    void insert(int value) {
        node *newNode = new node();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            newNode -> next = nullptr;
        }else {
            node *current = head;
            while (current -> next != nullptr) {
                if (current -> next -> data > value) {
                    newNode -> next = current->next;
                    current->next = newNode;
                    break;
                }else {
                    current = current->next;
                }
            }
        }
    }

    void deleteNode(int value) {
        bool deleted = false;
        if (head == nullptr) {
            cout << "Empty List.\n";
        }else if (head -> data == value) {
            node *temp = head;
            head = head -> next;
            delete temp;
            deleted = true;
        }else {
            node *current = head;
            while (current -> next != nullptr) {
                if (current -> next -> data == value) {
                    node *temp = current->next;
                    current->next = current->next -> next;
                    delete temp;
                    deleted = true;
                }
            }
            if (deleted == true) {
                cout << "Value had been deleted\n";
            }else {
                cout << "Value not found\n";
            }
        }
    }

    void search(int value) {
        node *current = head;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Value found{\n";
                break;
            }
            else if (current->data > value) {
                cout << "Value not found{\n";
                break;
            }else {
                current = current->next;
            }
        }
    }
};
