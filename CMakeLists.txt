cmake_minimum_required(VERSION 3.30)
project(finalCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(finalCode BinarySearch.cpp
        stack.cpp
        AVL.cpp
        Queue.cpp
        singleLinkedList.cpp
        doublyLinkedList.cpp
        sortingAlgorithms.cpp
        heapSort.cpp
        cmake-build-debug/Array-Based-List.cpp
        stack2.cpp
        "priority queue.cpp"
)
