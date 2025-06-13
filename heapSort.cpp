#include<iostream>
#include <vector>
using namespace std;

class heap {
    public:
    vector<int> array;

    //initialize the vector
    heap(int size) {
        int element;
        for (int i = 0; i < size; i++) {
            cin >> element;
            array.push_back(element);
        }
    }

    // return the parent of a node
    int parent(int i) {
        return (i - 1) / 2;
    }

    // return the right child of the node
    int right(int i) {
        return i*2+2;
    }

    //return the left child of the node
    int left(int i) {
        return i*2+1;
    }

    // achieve heap conditions
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

    // convert the array to heap using maxheapify
    void buildMaxHeap() {
        // get the array size
        int arrSize = array.size();
        // call max heapify for each node
        for(int i = (arrSize / 2) - 1; i >= 0; i--) {
            maxHeapify(i, arrSize);
        }
    }

    // sort the array using heap
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

    // get the largest element in the array
    int maxItem() {
        return array[0];
    }

    // get the largest element in the array then delete it
    int extractHeapMaximum() {
        int arrSize = array.size();
        if (arrSize == 0) {
            cout<<"empty heap"<<endl;
            return false;
        }else {
            int max = array[0]; // get the largest number of heap
            swap(array[0], array[arrSize - 1]); // let it be the last node to delete it
            array.pop_back(); // delete the max element
            arrSize = array.size(); // update the size after deleting, or you can paa arrsize - 2 in maxHeapify
            maxHeapify(0, arrSize - 1); // reheapify the array to be a valid heap
            return max; // return the max element
        }
    }

    // increase item in the heap and heapify it
    void heapIncreaseKey(int i, int key) {
        if (key < array[i]) {
            cout<<"key is smaller than the old value"<<endl;
        }else {
            array[i] = key;
            int parentIndex = parent(i);
            while (i > 0 && array[parentIndex] > array[i]) {
               swap(array[i], array[parentIndex]);
                i = parentIndex;
            }
        }
    }

    // add new value to the heap and confirm that it is agreed with heap's conditions
    void insert(int newValue) {
        array.push_back(-1e9); // let the new element = - infinity then increase it to the new value
        int arrSize = array.size();
        heapIncreaseKey(arrSize - 1, newValue);
    }

};