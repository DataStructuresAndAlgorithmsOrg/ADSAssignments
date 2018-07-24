//
//  integr_stack.cpp
//  assignment2
//
//  Created by Venkata.bankapalli on 24/07/18.
//  Copyright © 2018 Bankapalli. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
    int top;
    public:
        int a[MAX];
        bool push(int x);
        int pop();
        bool isEmpty();
        int peek();
        Stack () {top = -1;};
};

bool Stack::push(int x)
{
    if (top >= MAX-1)
    {
        cout << "Stack Overflow!!!\n";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

int Stack::pop ()
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

int Stack::peek()
{
    return a[top];
}

int main()
{
    cout << "Simple Stack That Stores Integers...\n";
    struct Stack stack;
    while (true)
    {
        int userSelection;
        cout << "Select the option for the operation that you want to perform on the stack...\n";
        cout << "1. Push\t2. Pop\t3. Peek\t4. IsStackEmpty\t5. Exit\t(Enter 1 or 2 or 3 or 4 or 5)\n";
        cin >> userSelection;
        switch (userSelection) {
            case 1:
                int valueToPush;
                cout << "Enter a interger value to push into Stack\n";
                cin >> valueToPush;
                stack.push(valueToPush);
                break;
            case 2:
                if (!stack.isEmpty())
                {
                    cout << "Popped value: " << stack.pop() << "\n";
                }
                else
                {
                    cout << "Cannot pop from an empty stack!\n";
                }
                break;
            case 3:
                if (!stack.isEmpty())
                {
                    cout << "Value at the top of the stack is: " << stack.peek() << "\n";
                }
                else
                {
                    cout << "Cannot peek into an empty stack!\n";
                }
                break;
            case 4:
                if (stack.isEmpty())
                {
                    cout << "Stack is empty\n";
                }
                else
                {
                    cout << "Stack is not empty\n";
                }
                break;
            case 5:
                exit(0);
            default:
                break;
        }
    }
    return 0;
}
