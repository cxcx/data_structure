#include "heap.h"

template <typename T> MaxHeap<T>::MaxHeap(int sz = MAX_SIZE)
{
    heap = new T[sz];
    courentSize = sz;
}

template <typename T> MaxHeap<T>::MaxHeap(T[] , int n)
{
    heap = new T[n];
    int i = 0;
    for(; i < n; i++)
        heap[i] = T[i];
    courentSize = n;
    siftDown(0);
}

MaxHeap::insert(const T &x)
{

}

void MaxHeap::siftDown(int posion)
{
    for(; posion < courentSize;)
    {
        int next_posion = posion * 2 + 1;
        if(heap[posion] < heap[next_posion])
        {
            int temp = heap[posion];
            heap[posion] = heap[next_posion];
            heap[next_posion] = temp;
        }
        posion = posion * 2 + 1;
    }
}

Heap::siftUp()
{

}
