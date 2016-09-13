#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 50

template <typename T> class MaxHeap;

template <typename T>
ostream& operator << (ostream &os, const MaxHeap<T> &heap);
template <typename T>
class MaxHeap{
public:
    MaxHeap(int sz = MAX_SIZE);
    MaxHeap(T a[], int n);
	~MaxHeap();
    bool insert(const T &x);
    T removeMax();
    bool isEmpty();
    bool isFull();
    void makeEmpty();
    friend ostream& operator<< <T> (ostream &os, const MaxHeap<T> &heap);
private:
    int courentSize;
    T* heap;
    void siftDown(int courient_posion, int posion);
    void siftUp(int posion);
};

template <typename T>
ostream& operator << (ostream &os, const MaxHeap<T> &s)
{
    int i = 0;
    for(; i < s.courentSize; i++)
    {
        os<<s.heap[i]<<" ";
    }
    os<<endl;
    return os;
}

template <typename T> MaxHeap<T>::MaxHeap(int sz)
{
    heap = new T[sz];
    courentSize = 0;
}

template <typename T> MaxHeap<T>::MaxHeap(T a[] , int n)
{
    heap = new T[n];
    int i = 0;
    for(; i < n; i++)
        heap[i] = a[i];
    courentSize = n;
    int courient_posion = (n - 2) / 2;
    while (courient_posion >= 0) {
        siftDown(courient_posion, courentSize - 1);
		courient_posion--;
    }
}

template <typename T>
bool MaxHeap<T>::insert(const T &x)
{
	if(courentSize == MAX_SIZE) return false;
	heap[courentSize] = x;
	courentSize++;
	siftUp(courentSize - 1);
    return true;
}

template <typename T>
T MaxHeap<T>::removeMax()
{
	T max = heap[0];
	heap[0] = heap[courentSize-1];
	courentSize--;
	siftDown(0, courentSize-1);
	return max;
}

template <typename T>
void MaxHeap<T>::siftDown(int courient_posion, int posion)
{
    int i = courient_posion, j = 2 * i + 1;
    T temp = heap[i];
    while (j <= posion) {
        if(heap[j] < heap[j+1]) j++;
        if(heap[i] < heap[j])
        {
            heap[i] = heap[j];
            heap[j] = temp;
			i = j;	
   			j = 2 * j + 1; 
		}
	}
}
template <typename T>
void MaxHeap<T>::siftUp(int posion)
{
	int i = posion, j = (i-1)/2;
	while(i > 0)
	{
		T temp = heap[i];
		if(heap[i] < heap[j]) break;
		if(heap[i] > heap[j])
		{
			heap[i] = heap[j];
			heap[j] = temp;
			i = j;
			j = (j-1)/2;
		}
	}
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
    delete heap;
}

#endif // HEAP_H
