#include<iostream>
#include <vector>
using namespace std;

class heap {
    public:
    vector<int> array;
    int length;

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
};