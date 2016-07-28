//
//  main.cpp
//  Caculator
//  将中缀表达式转换为后缀表达式
//  Created by JackChen on 7/18/16.
//  Copyright © 2016 ChenXin. All rights reserved.
//

#include "Stack.hpp"
string parseCaculataString(const string& caculateString);
bool isCacuChar(char c);
int ip(char c);

int main(int argc, const char * argv[]) {
    
    string str;
    cin>>str;
    string formulation_behind = parseCaculataString(str);
    cout<<formulation_behind<<endl;
    return 0;
}

string parseCaculataString(const string& caculateString)
{

    Stack<char> char_stack;
    string str;
    size_t length = caculateString.length();
    char temp;
    for (int i = 0; i < length; i++) {
        char c = caculateString.at(i);
        if (isCacuChar(c)) {
            if (ip(c) == 5) {
                while (char_stack.getTop(temp)) {
                    if (ip(temp) == 1) {
                        char_stack.pop(temp);
                        break;
                    }
                    char_stack.pop(temp);
                    str.append(1,temp);
                }
            }
            else if (ip(c) == 1)
            {
                char_stack.push(c);
            }
            else
            {
                if (!char_stack.isEmpty()) {
                    char_stack.getTop(temp);
                    if (ip(c) > ip(temp)) {
                        while (char_stack.getTop(temp)) {
                            if (ip(c) < ip(temp) || ip(temp) ==1) {
                                break;
                            }
                            char_stack.pop(temp);
                            str.append(1,temp);
                        }
                        char_stack.push(c);
                    }
                    else
                    {
                        char_stack.push(c);
                    }

                }
                else
                {
                    char_stack.push(c);
                }
            }
        }
        else
        {
            str.append(1,c);
        }
    }
    int size = char_stack.size();
    for (int i = 0; i < size; i++) {
        char_stack.pop(temp);
        str.append(1, temp);
    }
    return str;
}



int ip(char c)
{
    int p = 0;
    switch (c) {
        case '+':
            p = 4;
            break;
        case '-':
            p = 4;
            break;
        case '*':
            p = 3;
            break;
        case '/':
            p = 3;
            break;
        case '(':
            p = 1;
            break;
        case ')':
            p = 5;
        default:
            break;
    }
    return p;
}

bool isCacuChar(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
        return true;
    }
    return false;
}
