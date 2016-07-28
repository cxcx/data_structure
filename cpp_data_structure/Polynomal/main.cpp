//
//  main.cpp
//  Polynomal
//
//  Created by JackChen on 7/10/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#include <iostream>
#include "Polynomal.hpp"
int main(int argc, const char * argv[]) {
    
    Polynomal p,q;
    cin>>p;
    cout<<"p == "<<p<< endl;
    cin>>q;
    cout<<"q =="<<q<<endl;
    Polynomal r;
    r = q + p;
    cout<<"q + p == "<<r<<endl;
    return 0;
}
