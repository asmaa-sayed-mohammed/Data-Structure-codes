#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *previous;
};

class doublyLinkedList {
    public:
    Node *head;
    int length = 0;

    doublyLinkedList() {
        head = nullptr;
    }

    ~doublyLinkedList() {
        destroyList();
    }

    void insert(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            newNode->previous = nullptr;
            newNode->next = nullptr;
            length++;
        }else {
            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->previous = current;
            newNode->next = nullptr;
            length++;
        }
    }

    void insertAtBegin(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            head = newNode;
            newNode->previous = nullptr;
            newNode->next = nullptr;
            length++;
        }else {
            newNode -> previous = nullptr;
            newNode -> next = head;
            head = newNode;
        }

        length++;
    }

    void insertAt(int position, int value) {
        Node *newNode = new Node();
        newNode->data = value;
        Node *current = head;
        int location = 1;

        if (position == 1) {
            insertAtBegin(value);
        }
        if (position == 0) {
            cout << "position must be > 0." << endl;
            return;
        }else {
            while (current != nullptr && location < position - 1) {
                current = current->next;
                location++;
            }
            if (current == nullptr) {
                cout <<"position is out of range.\n";
            }else {
                Node *temp = current -> next;
                current -> next = newNode;
                newNode->previous = current;
                newNode->next = temp;
                temp->previous = newNode;
                length++;
            }
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void destroyList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
        }else {
            Node *current = head;
            while (current != nullptr) {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            length = 0;
        }
    }

    void printList() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << ", ";
            current = current->next;
        }
        cout << endl;
    }

    Node *end() {
        Node *current = head;
        while (current != nullptr) {
            current = current->next;
        }
        return current;
    }

    Node *first() {
        return head;
    }

    void printReverse() {
        Node *current = end();
        if (head == nullptr) {
            cout << "List is empty." << endl;
        }else {
            while (current != head) {
                cout << current->data << ", ";
                current = current->previous;
            }
            cout << endl;
        }
    }

    void search(int value) {
        Node *current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->data == value) {
                cout << current->data << " is found ";
                found = true;
                break;
            }
            current = current->next;
        }
        if (current->next == nullptr && found == false) {
            cout << "the value hadn't been found. :(" << endl;
        }

    }

    int firstItem() {
        return head->data;
    }

    int lastItem() {
        Node *last = end();
        return last->data;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            length++;
        }else if (head->data == value) {
            Node *temp = head;
            head = head->next;
            if (head != nullptr) {
                head->previous = nullptr;
            }
            delete temp;
        }else {
            Node *current = head;
            while (current != nullptr && current->data != value) {
                current = current->next;
            }
            if (current == nullptr) {
                cout << "The value is not found." << endl;
            }else {
                Node *temp = current;
                if (current->next != nullptr) {
                    current -> next -> previous = current -> previous;
                }
                if (current->previous != nullptr) {
                    current -> previous -> next = current->next;
                }
                delete temp;
            }
        }
        length--;
    }
};
