#include<iostream>
using namespace std;

class sorting_algorithm {
    int size = 10;
    int array[];
    public:

    void insertionSort(int arr[], int capacity) {
        for(int i = 1, j; i < capacity; i++) { // outer loop will be done n - 1 times
            int key = arr[i]; // this will be executed for each outer loop (n-1)
            for(j = i ; j > 0 && key < arr[j - 1]; j--) {// 1 + 2 + 3 + .... + n-1 = n power 2
                    arr[j] = arr[j - 1];
            }
            arr[j] = key; // o(n)
        }
    }

    void selectionSort(int arr[], int capacity) {
        for(int i = 0; i < capacity - 1; i++) { // -> n-1
            int min = i;
            for(int j = i + 1; j < capacity; j++) {
                if(arr[min] > arr[j]) {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
    }

    // every case buble sort --> complexity is o (n*n) for comparison
    void bubbleSort(int arr[], int capacity) {
        for(int i = 0; i < capacity - 1; i++) {
            for(int j = i + 1; j < capacity; j++) {
                if(arr[j + 1] > arr[j]) {
                    swap(arr[j + 1], arr[j]);
                }
            }
        }
    }

    // improved buble sort to make comparison be o(n)
    void improvedBubbleSort(int arr[], int capacity) {
        bool swap = false;
        for(int i = 0; i < capacity - 1; i++) {
            for(int j = i + 1; j < capacity; j++) {
                if(arr[j + 1] > arr[j]) {
                    swap(arr[j + 1], arr[j]);
                    swap = true;
                }
            }
            if(!swap) {
                break;
            }
        }
    }
};