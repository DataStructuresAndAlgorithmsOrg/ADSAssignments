//
//  char_stack.cpp
//  assignment3
//
//  Created by Venkata.bankapalli on 24/07/18.
//  Copyright © 2018 Bankapalli. All rights reserved.
//

#include <iostream>
using namespace std;


class Stack
{
    int top;
    long capacity;
public:
    char *a;
    bool push(string inputStr);
    char pop();
    bool isEmpty();
    char peek();
    Stack (long capacity)
    {
        this->top=-1;
        this->capacity=capacity;
        this->a=new char[capacity];
    };
    Stack ()
    {
        this->top=-1;
    }
};

bool Stack::push(string inputStr)
{
    if (top >= capacity-1)
    {
        cout << "Stack Overflow!!!\n";
        return false;
    }
    else
    {
        long lengthOfInputStr = inputStr.length();
        for (int i=0;i<lengthOfInputStr;i++)
        {
            this->a[++top] = inputStr[i];
        }
        return true;
    }
}

char Stack::pop ()
{
    if (top < 0)
    {
        cout << "Stack Underflow!!!\n";
        return 0;
    }
    else
    {
        int x = a[top];
        top=top-1;
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

char Stack::peek()
{
    return a[top];
}

string reverseString (Stack stack)
{
    string str;
    struct Stack tempStack1 = stack;
    while (!tempStack1.isEmpty())
    {
        str+=tempStack1.pop();
    }
    return str;
}

string readString (Stack stack)
{
    string str = "";
    struct Stack tempStack1 = stack;
    while (!tempStack1.isEmpty())
    {
        str=tempStack1.pop()+str;
    }
    return str;
}

int main()
{
    cout << "Simple Stack That Stores String...\n";
    
    cout << "Please enter a string to store into stack...\n";
    string inputStr;
    std::getline(std::cin, inputStr);
    long lengthOfInputStr = inputStr.length();
    struct Stack stack(lengthOfInputStr);
    stack.push(inputStr);
    cout << "String stored in stack is: " << readString(stack) << "\n";
    cout << "Reverse of the string stored in stack is: " << reverseString (stack) << "\n";
    return 0;
}
