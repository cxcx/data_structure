//
//  Polynomal.cpp
//  Polynomal
//
//  Created by JackChen on 7/10/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#include "Polynomal.hpp"

Term* Term::insertAfter(int e, float c)
{
    next = new Term(e, c);
    return next;
}

ostream& operator << (ostream& out, const Term& x)
{
    if (x.coef == 0) {
        return out;
    }
    out<<x.coef;
    switch (x.exp) {
        case 0:
            break;
        case 1:
            out<<"X";
            break;
        default:
            out<<"X^"<<x.exp;
            break;
    }
    return out;
}

Term* Polynomal::getHead()
{
    return first;
}

Polynomal::Polynomal()
{
    first = new Term(-1, 0);
}

//复制多项式
Polynomal::Polynomal(Polynomal& p)
{
    first = new Term(-1, 0);
    Term* temptr = p.getHead();
    Term* destptr = first;
    while (temptr->next != NULL) {
        destptr->insertAfter(temptr->exp, temptr->coef);
        temptr = temptr->next;
        destptr = destptr->next;
    }
}

//升序时最大次幂/Users/cx/Downloads/ps9sol.pdf
int Polynomal::maxOrder()
{
    Term* head = first;
    while (head->next != NULL) {
        head = head->next;
    }
    return head->exp;
}

ostream& operator << (ostream& out, Polynomal& x)
{
    Term* t = x.getHead()->next;
    bool h = true;
    while (t != NULL) {
        if (t->coef > 0 && h == false) {
            out<<"+";
        }
        h = false;
        out<<*t;
        t = t->next;
    }
    return out;
}

istream& operator >> (istream& in, Polynomal& x)
{
    Term* head = x.getHead();
    int e, c;
    while (1) {
        cout<<"Please input c ane e: ";
        in>>c>>e;
        if (e < 0) break;
        head = head->insertAfter(e, c);
    }
    return in;
}

Polynomal operator + (Polynomal& a, Polynomal& b)
{
    Polynomal result;
    Term* head = result.getHead();
    Term* head_a = a.getHead();
    Term* head_b = b.getHead();
    while (head_a->next != NULL && head_b->next != NULL)
    {
        if (head_a->next->exp == head_b->next->exp)
        {
            head = head->insertAfter(head_a->next->exp , head_a->next->coef + head_b->next->coef);
            head_a = head_a->next;
            head_b = head_b->next;
        }
        else if (head_a->next->exp > head_b->next->exp)
        {
            head = head->insertAfter(head_b->next->exp, head_b->next->coef);
            head_b = head_b->next;
        }
        else
        {
            head = head->insertAfter(head_a->next->exp, head_a->next->coef);
            head_a = head_a->next;
        }
    }
    while (head_a->next != NULL)
    {
        head = head->insertAfter(head_a->next->exp, head_a->next->coef);
        head_a = head_a->next;
    }
    while (head_b->next != NULL)
    {
        head = head->insertAfter(head_b->next->exp, head_b->next->coef);
        head_b = head_b->next;
    }
    return result;
}

