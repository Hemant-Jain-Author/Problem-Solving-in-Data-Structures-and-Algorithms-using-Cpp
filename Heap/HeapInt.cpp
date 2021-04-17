#include "HeapInt.h"

int main1()
{
    Heap hp = Heap(true);
    hp.add(1);
    hp.add(9);
    hp.add(6);
    hp.add(7);
    hp.print();
    while(hp.isEmpty() == false)  {
        std::cout << hp.remove() << " " ; 
    }
    std::cout << std::endl;
    return 0;
}
/*
Printing content of heap :: 1 7 6 9 
1 6 7 9 
*/
int main2()
{
    std::vector<int> a = {1, 0, 2, 4, 5, 3};
    Heap hp = Heap(a, true);// Min Heap
    hp.print();
    while(hp.isEmpty() == false)  {
        std::cout << hp.remove() << " " ; 
    }
    std::cout << std::endl;
    return 0;
}  
/*
Printing content of heap :: 0 1 2 4 5 3 
0 1 2 3 4 5 
*/

int main()
{
    std::vector<int> a = {1, 0, 2, 4, 5, 3};
    Heap hp = Heap(a, false);// Max Heap
    hp.print();
    while(hp.isEmpty() == false)  {
        std::cout << hp.remove() << " " ; 
    }
    std::cout << std::endl;
    return 0;
}  
/*
Printing content of heap :: 0 1 2 4 5 3 
0 1 2 3 4 5 
*/

int main4()
{
    std::vector<int> a = { 1, 9, 6, 7, 8, -1, 2, 4, 5, 3 };
    Heap::heapSort(a, true);
    std::cout << "value after heap sort :: ";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}
/*
value after heap sort :: -1 1 2 3 4 5 6 7 8 9 
*/

Heap::Heap(bool isMin)
{
    arr = std::vector<int>(CAPACITY);
    size = 0;
    isMinHeap = isMin;
}

Heap::Heap(std::vector<int> &array_in, bool isMin)
{
    size = array_in.size();
    arr = array_in;
    isMinHeap = isMin;

    // Build Heap operation over array
    for (int i = (size / 2); i >= 0; i--)
    {
        proclateDown(i);
    }
}

int Heap::length()
{
    return arr.size();
}


bool Heap::compare(int first, int second)
{
    if (isMinHeap)
        return (first - second) > 0; // Min heap compare
    else
        return (first - second) < 0; // Max heap compare
}

void Heap::proclateDown(int parent)
{
    int lChild = 2 * parent + 1;
    int rChild = lChild + 1;
    int child = -1;
    int temp;

    if (lChild < size)
    {
        child = lChild;
    }

    if (rChild < size && compare(arr[lChild], arr[rChild]))
    {
        child = rChild;
    }

    if (child != -1 && compare(arr[parent], arr[child]))
    {

        temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
        proclateDown(child);
    }
}

void Heap::proclateUp(int child)
{
    int parent = (child - 1) / 2;
    int temp;
    if (parent < 0)
    {
        return;
    }

    if (compare(arr[parent], arr[child]))
    {
        temp = arr[child];
        arr[child] = arr[parent];
        arr[parent] = temp;
        proclateUp(parent);
    }
}

void Heap::add(int value)
{
    if (size == arr.size())
    {
        doubleSize();
    }

    arr[size++] = value;
    proclateUp(size-1);
}

void Heap::doubleSize()
{
    std::vector<int> old = arr;
    arr = std::vector<int>(arr.size() * 2);
    for (int i =0; i<size; i++)
    {
        arr[i] = old[i];
    }
}

int Heap::remove()
{
    if (isEmpty())
        throw "HeapEmptyException.";

    int value = arr[0];
    arr[0] = arr[size-1];
    size--;
    proclateDown(0);
    return value;
}

void Heap::print()
{
    std::cout << "Printing content of heap :: " ;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

bool Heap::isMinHeapArr(std::vector<int> &arr, int size)
{
    for (int i = 0; i <= (size - 2) / 2; i++)
    {
        if (2 * i + 1 < size)
        {
            if (arr[i] > arr[2 * i + 1])
            {
                return false;
            }
        }
        if (2 * i + 2 < size)
        {
            if (arr[i] > arr[2 * i + 2])
            {
                return false;
            }
        }
    }
    return true;
}

bool Heap::isMaxHeapArr(std::vector<int> &arr, int size)
{
    for (int i = 0; i <= (size - 2) / 2; i++)
    {
        if (2 * i + 1 < size)
        {
            if (arr[i] < arr[2 * i + 1])
            {
                return false;
            }
        }
        if (2 * i + 2 < size)
        {
            if (arr[i] < arr[2 * i + 2])
            {
                return false;
            }
        }
    }
    return true;
}

bool Heap::isEmpty()
{
    return (size == 0);
}

int Heap::peek()
{
    if (isEmpty())
        throw "Heap empty exception.";

    return arr[0];
}

void Heap::heapSort(std::vector<int> &array, bool inc)
{
    Heap hp = Heap(array, !inc);
    for (int i = 0; i < array.size(); i++)
    {
        array[array.size() - i - 1] = hp.remove();
    }
}
