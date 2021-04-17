#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class Heap
{
private:
    static const int CAPACITY = 16;
    int size; // Number of elements in heap.
    std::vector<int> arr; // Array to store heap.
    bool isMinHeap;

public:
    Heap(bool isMin);
    Heap(std::vector<int> &array_in, bool isMin);
    // Other Methods.

private:
    void proclateDown(int position);
    void proclateUp(int position);
    bool compare(int first, int second);
    void doubleSize();


public:
    virtual void add(int value);
    virtual int remove();
    virtual void print();
    virtual int length();
    virtual bool isMinHeapArr(std::vector<int> &arr, int size);
    virtual bool isMaxHeapArr(std::vector<int> &arr, int size);
    virtual bool isEmpty();
    virtual int peek();
    static void heapSort(std::vector<int> &array, bool inc);
};
