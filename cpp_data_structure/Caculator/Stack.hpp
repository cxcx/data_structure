//
//  Stack.hpp
//  Stack
//
//  Created by JackChen on 7/18/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
using namespace std;

template <typename T>
class Stack{
private:
    T* bottom;
    int top;
    int max_count;
    
public:
    Stack(int size = 50):max_count(size), top(-1), bottom(new T[size]) {};
    ~Stack()
    {
        delete [] bottom;
    }
    bool push(const T& parm)
    {
        if (isFull()) {
            return false;
        }
        bottom[++top] = parm;
        return true;
    }
    bool pop(T& parm)
    {
        if (isEmpty()) {
            return false;
        }
        parm = bottom[top--];
        return true;
    }
    bool getTop(T& t)
    {
        if (isEmpty()) {
            return false;
        }
        t = bottom[top];
        return true;
    }
    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
    
    bool isFull()
    {
        return top == max_count - 1 ? true : false;
    }
    int size()
    {
        return top+1;
    }
    
    friend ostream& operator<<(ostream& out, Stack<T> &parm)
    {
        out<<"有"<<parm.top + 1<<"个元素"<<endl;
        for (int i = 0; i < parm.top + 1; i++) {
            out<<i<<" : "<<parm.bottom[i]<<endl;
        }
        return out;
    }
};

#endif 
