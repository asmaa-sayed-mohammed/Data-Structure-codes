#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
    int priority;
};
class priority_queue {
    node *head, *rear;
    int size;
    public:
    priority_queue() {
        head = nullptr;
        rear = nullptr;
        size = 0;
    }

    ~priority_queue() {
        clear();
    }

    void clear() {
        while (size != 0) {
            dequeue();
        }
    }

    void enqueue(int value, int arrange) {
        node *newNode = new node;
        newNode->data = value;
        newNode-> priority = arrange;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            rear = newNode;
        }else {
            if (rear -> priority <= newNode -> priority) {
                rear ->next = newNode;
                newNode->prev = rear;
                rear = newNode;
                newNode->next = nullptr;
            }else if (head -> priority > newNode -> priority) {
                newNode->next = head;
                head -> prev = newNode;
                head = newNode;
                newNode->prev = nullptr;
            }else if (head -> priority == newNode -> priority && rear == head) {
                head -> next = newNode;
                newNode->prev = head;
                newNode->next = nullptr;
            }else {
                node *temp = rear;
                while (temp -> priority > newNode -> priority) {
                    temp = temp -> prev;
                }
                if (temp -> next != nullptr) {
                    temp -> next -> prev = newNode;
                }else {
                    rear = newNode;
                }
                temp -> next = newNode;
            }
        }
        size++;
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Empty Queue.\n";
        }else {
            if (size == 1) {
                node *temp = head;
                head = nullptr;
                rear = nullptr;
                delete temp;
                size--;
            }else {
                node *temp = head;
                head = head -> next;
                head -> prev = nullptr;
                delete temp;
                size--;
            }
        }
    }

    bool isEmpty() {
       if (size == 0) {
           return true;
       }else {
           return false;
       }
    }

    int first() {
        if (size == 0) {
            cout << "Empty Queue.\n";
            return -1;
        }else {
            return head -> data;
        }
    }

};