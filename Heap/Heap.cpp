#include "Heap.h"
#include <exception>

template<typename T>
Heap<T>::Heap(int (*cmp)(T, T))
{
    arr = std::vector<T>(CAPACITY);
    size = 0;
}

template<typename T>
Heap<T>::Heap(std::vector<T> &input_array, int (*cmp)(T, T))
{
    size = input_array.size();
    arr = std::vector<T>(input_array.size() + 1);
    compare = cmp;
    for (int i = 0; i < size; i++)
    {
        arr[i + 1] = input_array[i];
    }

    // Build Heap operation over array
    for (int i = (size / 2); i > 0; i--)
    {
        proclateDown(i);
    }
}

template<typename T>
void Heap<T>::proclateDown(int position)
{
    int lChild = 2 * position;
    int rChild = lChild + 1;
    int small = -1;
    T temp;

    if (lChild < size)
    {
        small = lChild;
    }

    if (rChild < size && compare(arr[rChild], arr[lChild]) < 0)
    {
        small = rChild;
    }

    if (small != -1 && compare(arr[small], arr[position]) < 0)
    {
        temp = arr[position];
        arr[position] = arr[small];
        arr[small] = temp;
        proclateDown(small);
    }
}

template<typename T>
void Heap<T>::proclateUp(int position)
{
    int parent = position / 2;
    T temp;
    if (parent == 0)
    {
        return;
    }

    if (compare(arr[parent], arr[position]) < 0)
    {
        temp = arr[position];
        arr[position] = arr[parent];
        arr[parent] = temp;
        proclateUp(parent);
    }
}

template<typename T>
void Heap<T>::add(T value)
{
    if (size == arr.size() - 1)
    {
        doubleSize();
    }

    arr[++size] = value;
    proclateUp(size);
}

template<typename T>
void Heap<T>::doubleSize()
{
    std::vector<T> old = arr;
    arr = std::vector<T>(arr.size() * 2);
    for (int i =1; i<size; i++)
    {
        arr[i] = old[i];
    }
}

template<typename T>
T Heap<T>::remove()
{
    if (isEmpty())
    {
        throw "HeapEmptyException";
    }

    T value = arr[1];
    arr[1] = arr[size];
    size--;
    proclateDown(1);
    return value;
}

template<typename T>
void Heap<T>::print()
{
    for (int i = 1; i <= size; i++)
    {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

}

template<typename T>
bool Heap<T>::isEmpty()
{
    return (size == 0);
}

template<typename T>
T Heap<T>::peek()
{
    if (isEmpty())
    {
        throw "HeapEmptyException";
    }
    return arr[1];
}

template<typename T>
void Heap<T>::heapSort(std::vector<int> &array_variable, int (*cmp)(T, T) )
{
    Heap<int> *hp = new Heap<int>(array_variable, cmp);
    for (int i = 0; i < array_variable.size(); i++)
    {
        array_variable[i] = hp->remove();
    }
}
int compare(int a, int b)
{
    return a - b;
}

int main()
{
    std::vector<int> a = { 1, 9, 6, 7, 8, 0, 2, 4, 5, 3 };
    Heap<int> *hp = new Heap<int>(a, &compare);
    hp->print();
    for (unsigned int i = 0; i < a.size(); i++)
    {
        std::cout << "pop value :: " << hp->remove() << std::endl;
    }

    int num[] = { 1, 9, 6, 7, 8, 0, 2, 4, 5, 3 };
    Heap<int>::heapSort(a, &compare);
    for (unsigned int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}
/*
0 4 1 5 8 6 2 7 9 3
pop value :: 0
pop value :: 1
pop value :: 2
pop value :: 3
pop value :: 4
pop value :: 5
pop value :: 6
pop value :: 7
pop value :: 8
pop value :: 9
0 1 2 3 4 5 6 7 8 9
*/