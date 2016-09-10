#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 50

template <typename T>
class MaxHeap{
public:
    MaxHeap(int sz = MAX_SIZE);
    MaxHeap(T[], int n);
	~MaxHeap();
    bool insert(const T& x);
    bool remove(T& x);
    bool isEmpty();
    bool isFull();
    void makeEmpty();

private:
    int courentSize;
    T* heap;
    void siftDown(int posion);
    void siftUp(int posion);
};
#endif // HEAP_H
