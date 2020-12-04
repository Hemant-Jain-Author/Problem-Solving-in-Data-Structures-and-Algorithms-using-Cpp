#include <string>
#include <vector>
#include <iostream>

template<typename T>
class Heap
{
private:
    static const int CAPACITY;
    int size;
    std::vector<T> arr;
    int (*compare)(T, T);
    void proclateDown(int position);
    void proclateUp(int position);
    void doubleSize();
public:
    Heap(int (*cmp)(T, T));
    Heap(std::vector<T> &array_variable, int (*cmp)(T, T));
    virtual void add(T value);
    virtual T remove();
    virtual void print();
    virtual bool isEmpty();
    virtual T peek();
    static void heapSort(std::vector<int> &array_variable, int (*cmp)(T, T));
};
