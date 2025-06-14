#include<iostream>
#include<vector>
#include<algorithm>
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

    vector<int> count(vector<int>& arr) { // o(n + k)
        int maxItem = *( max_element(arr.begin(), arr.end()) ); //get the maximum item of array
        vector<int> count(maxItem + 1, 0);//initialize the size of vector to be the maximum item in arr + 1 and initialize as 0
        vector<int>sorted(arr.size());// new array to save the sorted array
        for(int i = 0; i < arr.size(); i++) {// o(n)
            count[arr[i]]++; // count each element how many was appeared in the array
        }
        for(int i = 1; i < count.size() + 1; i++) { //o(n)
            count[i] += count[i - 1]; // sum each element with the previous one(prefix sum)
        }
        for (int i = arr.size() - 1; i >= 0; i--) { //o(n)
            sorted[--count[arr[i]]] = arr[i];
        }
        return sorted;
    }

    void radixsort(vector<int>& arr) {
        vector<int>v(10);
        vector<int>sorted(arr.size());
        int max = *max_element(arr.begin(), arr.end());
        for(int div = 1; max/div > 0; div *= 10) {

            for (int i = 0; i < 10; i++) {
                v[i] = 0;
            }
            for(int i = 0; i < arr.size(); i++) {
                int digit = arr[i] / div;
                v[digit % 10]++;
            }
            for(int i = 1; i < 10; i++) {
                v[i] += v[i - 1];
            }
            for (int i = arr.size() - 1; i >= 0; i--) {
                int digit = arr[i] / div;
                sorted[--v[digit % 10]] = arr[i];
            }
            arr = sorted;

        }
    }


    void merge(int arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1; // size of left part
        int n2 = r - m;     // size of right part

        int *L = new int[n1], *R = new int[n2]; // create temp arrays for left and right

        // copy data to L[]
        for (i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }

        // copy data to R[]
        for (j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        i = j = 0; // initial index for L[] and R[]
        k = l;     // initial index for merged array

        // merge the two arrays into original array
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // copy remaining elements of L[]
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // copy remaining elements of R[]
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        // print merged part (for debugging)
        cout << "After merging: ";
        for (int x = l; x <= r; x++) {
            cout << arr[x] << " ";
        }
        cout << endl;

        delete[] L;
        delete[] R;
    }


    void merge_sort(int arr[], int l, int r) {
        if (l >= r) {
            return; // base case: 1 element
        }

        int mid = l + (r - l) / 2; // find middle index

        merge_sort(arr, l, mid);      // sort left half
        merge_sort(arr, mid + 1, r);  // sort right half

        merge(arr, l, mid, r);        // merge both halves
    }


    // we will use 2d array to divide the main array into buckets
    void bucket_sort(int arr[], int size) {
        const int bucketNumbers = 10; // total number of buckets
        int bucketSie = size; // max number of elements in each bucket
        int buckets[bucketNumbers][bucketSie]; // array of buckets
        int number_of_elements[bucketNumbers] = {0}; // number of elements in each bucket

        // put each element in its correct bucket
        for (int i = 0; i < size; i++) {
            int bucketNum = arr[i] / 10; // find bucket index
            if (bucketNum >= bucketNumbers) {
                bucketNum = bucketNumbers - 1; // make sure index is in range
            }
            if (number_of_elements[bucketNum] < bucketSie) {
                buckets[bucketNum][number_of_elements[bucketNum]++] = arr[i]; // insert into bucket
            }
        }

        // print the buckets
        cout << "Buckets:\n";
        cout << "-----------\n";
        for (int i = 0; i < bucketNumbers; i++) {
            cout << "Buckets[" << i << "]:\n";
            for (int j = 0; j < number_of_elements[i]; j++) {
                cout << buckets[i][j] << " ";
            }
            cout << endl;
        }

        int index = 0;
        // sort each bucket and copy back to arr
        for (int i = 0; i < bucketNumbers; i++) {
            if (number_of_elements[i] > 0) {
                merge_sort(buckets[i], 0, number_of_elements[i] - 1); // sort bucket
                for (int j = 0; j < number_of_elements[i]; j++) {
                    arr[index++] = buckets[i][j]; // copy to original array
                }
            }
        }
    }









};