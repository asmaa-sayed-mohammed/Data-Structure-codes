#include<iostream>
#include <vector>
using namespace std;

class heap {
    public:
    vector<int> array;

    heap(int size) {
        int element;
        for (int i = 0; i < size; i++) {
            cin >> element;
            array.push_back(element);
        }
    }

    int right(int i) {
        return i*2+2;
    }

    int left(int i) {
        return i*2+1;
    }

    void maxHeapify(int i, int n) {
        int largest = i; //initialize the largest num as the index you have passed to function
        int l = left(i); // get the left child
        int r = right(i); // get the right child
        if(l < n && array[l] > array[largest]) { // if the left child > the largest make the largest = left
            largest = l;
        }
        if(r < n && array[r] > array[largest]) {// if the right child > the largest make the largest = right
            largest = r;
        }
        if(largest != i) {
            // if largest not the index you have passed swap it wit the index
            swap(array[i], array[largest]);
            // recall it to the node you have swapped to make sure that all array is heapify
            maxHeapify(largest, n);
        }
    }

    void buildMaxHeap() {
        // get the array size
        int arrSize = array.size();
        // call max heapify for each node
        for(int i = (arrSize / 2) - 1; i >= 0; i--) {
            maxHeapify(i, arrSize);
        }
    }

    void heapSort() {
        buildMaxHeap();
        int arrSize = array.size();
        for(int i = arrSize - 1; i >= 0; i--) {
            // each iteration a[0] will be the largest element so we will add it at the end of array
            swap(array[i], array[0]);
            // do max heapify for each node till you reach to the last node don't do for the node you have swapped it to the last
            // all last nodes you have swapped before are already in the right place
            maxHeapify(0, i);
        }
    }

    int maxItem() {
        return array[0];
    }
};