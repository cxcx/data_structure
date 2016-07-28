//
//  Polynomal.hpp
//  Polynomal
//
//  Created by JackChen on 7/10/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#ifndef Polynomal_hpp
#define Polynomal_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

struct Term {
    int exp;
    float coef;
    Term* next;
    Term(int e, float c, Term* n = NULL)
    {
        exp = e;
        coef = c;
        next = n;
    }
    Term* insertAfter(int e, float c);
    friend ostream& operator << (ostream& out, const Term& x);
};


class Polynomal {
    
private:
    Term* first;
    
    
public:
    Polynomal();
    Polynomal(Polynomal& p);
    int maxOrder();
    Term* getHead();
    friend ostream& operator << (ostream& out, Polynomal& x);
    friend istream& operator >> (istream& in, Polynomal& x);
    friend Polynomal operator + (Polynomal &x1, Polynomal &x2);
    friend Polynomal operator * (Polynomal &x1, Polynomal &x2);
};


#endif /* Polynomal_hpp */
