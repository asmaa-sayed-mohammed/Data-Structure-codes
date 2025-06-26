#include <iostream>
using namespace std;

class StackLinkedlist {

    struct node {
        string data;
        node *next = NULL;
    };

    node *top = NULL;

public:
    void push(string data) {
        node *newNode = new node;
        newNode->data = data;

        if (top == NULL) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        }else {
            node *del = top;
            top = top->next;
            delete del;
        }
    }

    void clear() {
        while (top != NULL) {
            pop();
        }
    }

    string peek() {
        string current = top->data;
        return current;
    }

    bool isEmpty() {
        if (top == NULL) {
            return true;
        }else {
            return false;
        }
    }

    void display() {
        node *print = top;
        while (print != NULL) {
            cout << print->data << ", ";
            print = print->next;
        }
        if (print == NULL) {
            cout << " ";
        }
    }

    int StackSize() {
        int counter = 0;
        node *print;
        print = top;
        while (print != NULL) {
            print = print->next;
            counter++;
        }
        return counter;
    }
};

