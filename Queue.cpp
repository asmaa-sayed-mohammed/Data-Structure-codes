#include<iostream>
using namespace std;

/*
 * advantages for using array:
 * 1 - simple implementation.
 * 2 - you can use only indexing in dequeue and enqueue
 * ------------------------------------------------------
 * disadvantages:
 * 1 - wasted memory the parts that you want to remove still in the memory.
 * 2 - in deque(you want to shift elements so the complexity is o(n))
 */

class queue_using_array {
    int maxsize = 10;
    int length;
    int *arr;
    public:

    queue_using_array() {
        arr = new int[maxsize];
        length = 0;
    }

    ~queue_using_array() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (length == maxsize) {
            cout << "Queue is full" << endl;
            return;
        }else {
            arr[length] = value;
            length++;
        }
    }

    int dequeue() {
        int temp;
        if (length == 0) {
            cout << "Queue is empty" << endl;
            return 0;
        }else {
            temp = arr[0];
            for (int i = 0; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
            return temp;
        }

    }

    bool isEmpty() {
        if (length == 0) {
            return true;
        }else {
            return false;
        }
    }

    int first() {
        if (length == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }else {
            return arr[0];
        }
    }

    void clear() {
        delete[] arr;
        length = 0;
    }
};

/*
 * advantages:
 * 1 - no wasted space after removing element.
 * 2 - no shifting in dequeue which is decreasing the time complexity
 * 3 - faster in enqueue and dequeue(o(1))
 * 4 - use it in fixed size array
 * -----------------------------------------------------------------------
 * disadvantages:
 * you need to use fixed size.
 * you need to handle wrapping
 * harder in understand
 */

class queue_using_circular_array {
    int maxsize;
    int length;
    int front, rear;
    int *arr;
    public:
    queue_using_circular_array(int capacity) {
        maxsize = capacity;
        length = 0;
        front = -1;
        arr = new int[maxsize];
        rear = -1;
    }

    ~queue_using_circular_array() {
        delete[] arr;
    }

    bool isEmpty() {
        if (length == 0) {
            return true;
        }else {
            return false;
        }
    }

    bool isFull() {
        if (length == maxsize) {
            return true;
        }else {
            return false;
        }
    }

    void clear() {
        delete[] arr;
        front = -1;
        rear = -1;
        length = 0;
    }

    int first() {
        if (length == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }else {
            return arr[front];
        }
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        }else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % maxsize;
            arr[rear] = value;
            length++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            int temp = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }else {
                front = (front + 1) % maxsize;
            }
            length--;
            return temp;
        }
    }
};

/*
 * advantages:
 * 1 - need small space.
 * 2 - no wasted space in book memory
 * 3 - small complexity all poeration (o(1))
 * ----------------------------------------------
 * disadvantages:
 * 1 - you can't go back in queeue.
 * 2 - need deep understant in using pointers.
 */
struct node {
    int data;
    node *next;
};

class queue_using_single_linked_list {
    node *front, *rear;
    int size;
    public:
    queue_using_single_linked_list() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    ~queue_using_single_linked_list() {
        clear();
    }

    void clear() {
        node *current = front;
        while (current != nullptr) {
            node *temp = current;
            current = current->next;
            delete temp;
        }
        front = nullptr;
        rear = nullptr;
        size = 0;
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
            cout << "Queue is empty" << endl;
            return -1;
        }else {
            return front->data;
        }
    }

    void enqueue(int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = nullptr;
        if (isEmpty()) {
            front = temp;
            rear = temp;
        }else {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        }else {
            node *temp = front;
            front = front->next;
            delete temp;
            size--;
            if (size == 0) {
                front = nullptr;
                rear = nullptr;
            }
        }
    }
};

/*
 * advantages:
 * 1 - you can go back it will be better in special types of queue.
 * -----------------------------------------------------------------
 * disadvantages:
 * 1 - more complex.
 * 2 - you don't want to use it if you implement a general queue
 * 3 - wasted memory in general queue (you will have additional pointer in memory)
 * 4 - you want to be very carefully in join pointers.
 */

struct nodeddl {
    int data;
    nodeddl *next;
    nodeddl *previous;
};

class queue_using_doubly_list {
    nodeddl *front, *rear;
    int size;
    public:
    queue_using_doubly_list() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    ~queue_using_doubly_list() {
        clear();
    }

    void clear() {
        nodeddl *current = front;
        while (current != nullptr) {
            nodeddl *temp = current;
            current = current->next;
            delete temp;
        }
        front = nullptr;
        rear = nullptr;
        size = 0;
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
            cout << "Queue is empty" << endl;
            return -1;
        }else {
            return front->data;
        }
    }

    void enqueue(int value) {
        nodeddl *temp = new nodeddl;
        temp->data = value;
        if (isEmpty()) {
            front = temp;
            rear = temp;
            temp->next = nullptr;
            temp->previous = nullptr;
        }else {
            temp -> next = nullptr;
            temp -> previous = rear;
            rear -> next = temp;
            rear = temp;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }else {
            if (size == 1) {
                nodeddl *temp = front;
                front = nullptr;
                rear = nullptr;
                delete temp;
                size--;
            }else {
                nodeddl *current = front;
                front = front->next;
                if (front != nullptr) {
                    front ->previous = nullptr;
                }
                delete current;
                size--;
            }
        }
    }
};