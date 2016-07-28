//
//  main.cpp
//  Stack
//
//  Created by JackChen on 7/18/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    Stack<string> s(20);
    s.push("safa");
    s.push("fadsa");
    cout<<s;
    return 0;
}
