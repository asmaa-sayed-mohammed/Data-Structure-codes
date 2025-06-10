#include <assert.h>
#include <iostream>
using namespace std;

class ArrayBasedList {
    int maxSize;
    int length;
    int *arr;
    public:
    ArrayBasedList(int size) {
        if (size < 1) {
            cout << "Array size must be greater than 0, we make it 100 as default" << endl;
            maxSize = 100;
        }else {
            maxSize = size;
        }
        arr = new int[maxSize];
        length = 0;
    }

    // copy an old object to a new object while it is initializing
    ArrayBasedList(ArrayBasedList &list) {
        maxSize = list.maxSize;
        length = list.length;
        arr = new int[maxSize];
        for (int i = 0; i < length; i++) {
            arr[i] = list.arr[i];
        }
    }

    /*
     * we use it to copy an old object to another old object , both were initialized before
     * Before copying the data we should delete an old data in the object which is before the assignment operator
     */
    ArrayBasedList &operator=(const ArrayBasedList &list) {
        if (this != &list) {
            delete[] arr;
            maxSize = list.maxSize;
            length = list.length;
            arr = new int[maxSize];
            for (int i = 0; i < length; i++) {
                arr[i] = list.arr[i];
            }
        }
        return *this;
    }

    ~ArrayBasedList() {
        delete[] arr;
    }

    bool isFull() {
        return length == maxSize;
    }

    bool isEmpty() {
        return length == 0;
    }

    int getMaxSize() {
        return maxSize;
    }

    int getLength() {
        return length;
    }

    void print() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertAt(int position, int value) {
        if (isFull()) {
            cout << "array is full\n";
        } else if (position > length || position < 0) {
            cout << "position out of bounds\n";
        } else {
            // shift each element to the next position (if the position = length the code doesn't perform the loop and go to the position direct)
            for (int i = length; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = value;
            length++;
        }
    }

    void insertEnd(int value) {
        if (isFull()) {
            cout << "array is full\n";
        } else {
            arr[length] = value;
            length++;
        }
    }

    void removeAt(int position) {
        if (isEmpty()) {
            cout << "array is empty\n";
        }else if (position > length || position < 0) {
            cout << "position out of bounds\n";
        }else {
            for (int i = position; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
        }
    }

    void retrieveAt(int position, int &item) {
        if (isEmpty()) {
            cout << "array is empty\n";
        }else if (position > length || position < 0) {
            cout << "position out of bounds\n";
        }else {
             item = arr[position];
        }
    }

    void replaceAt(int position, int value) {
        if (isEmpty()) {
            cout << "array is empty\n";
        }
        else if (position > length || position < 0) {
            cout << "position out of bounds\n";
        } else {
            arr[position] = value;
        }
    }

    void clear() {
        length = 0;
    }

    int searchItem(int value) {
        bool found = false;
        int item;
        if (isEmpty()) {
            cout << "array is empty\n";
        }else {
            for (int i = 0; i < length; i++) {
                if (arr[i] == value) {
                    found = true;
                    item = i;
                    break;
                }
            }
            if (found == true) {
                return item;
            }else {
                return -1;
            }
        }

    }
};
