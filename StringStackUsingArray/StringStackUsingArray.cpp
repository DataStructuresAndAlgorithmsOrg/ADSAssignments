//
//  StackOfStringsUsingArray.cpp
//
//  Stack of words using array of character array
//
//  Created by Venkata.bankapalli on 10/09/18.
//  Copyright © 2018 Bankapalli. All rights reserved.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_LENGHT_OF_STACK 10
// Technically pneumonoultramicroscopicsilicovolcanoconiosis is the longest word in dictionary.
// It has 45 letters in it, so declaring the maximum length of each word in the stack to be 50 characters.
#define MAX_LENGTH_OF_EACH_WORD_IN_STACK 50

class Stack
{
    private:
        int top;
        char a[MAX_LENGHT_OF_STACK][MAX_LENGTH_OF_EACH_WORD_IN_STACK];
    public:
        /*
        bool push(string inputStr);
        char* pop();
        bool isEmpty();
        char* peek();
        void traverseStack ();
        */
        Stack ()
        {
            this->top=-1;
        }

        bool isEmpty()
        {
            return (top < 0);
        }

        void traverseStack ()
        {
            if (!isEmpty())
            {
                cout << "Elements in the stack: ";
                for (int i=top;i>=0;i--)
                {
                    if (i == 0)
                    {
                        cout << a[i] << "\n";
                    }
                    else
                    {
                        cout << a[i] << ", ";
                    }
                }
            }
            else
                cout << "Stack is empty! \n";
        }

        bool push(string inputStr)
        {
            /*
            int n = inputStr.length();  
            char inputChar[MAX_LENGTH_OF_EACH_WORD_IN_STACK];  
            strcpy(inputChar, inputStr.c_str());  

            for (int i=0; i<n; i++) 
              cout << inputChar[i];
              cout << "\n";
            */
            if (top >= MAX_LENGHT_OF_STACK-1)
            {
                cout << "Stack Overflow!!!\n";
                return false;
            }
            else
            {
                int x = ++top;
                strcpy(this->a[x], inputStr.c_str());
                return true;
            }
        }

        char* pop ()
        {
            if (top < 0)
            {
                cout << "Stack Underflow!!!\n";
                return 0;
            }
            else
            {
                char* x = a[top];
                top=top-1;
                return x;
            }
        }

        char* peek()
        {
            return a[top];
        }        
};

int getNumberOfSpacesInString(char inputStr[])
{
    int count = 0;
    for(int i = 0; inputStr[i] != '\0'; ++i) {
        if (' '  == inputStr[i])
            count++;
    }
    return ( count>0?++count:count );
}

int main()
{
    cout << "Simple Stack That Stores Words...\n";
    
    struct Stack stack;
    while (true)
    {
        int userSelection;
        cout << "Select the option for the operation that you want to perform on the stack...\n";
        cout << "1. Push\t2. Pop\t3. Peek\t4. TraverseStack\t5. IsStackEmpty\t6. Exit\n(Enter 1 or 2 or 3 or 4 or 5 or 6)\n";
        cin >> userSelection;

        if (1 == userSelection) 
        {
            string valueToPush;
            cout << "Enter a word value to push into Stack\n";
            cin >> valueToPush;
            cout << "Input String is: " << valueToPush << "\n";
            stack.push(valueToPush);
        }
        else if (2 == userSelection) 
        {
            if (!stack.isEmpty())
            {
                cout << "Popped value: " << stack.pop() << "\n";
            }
            else
            {
                cout << "Cannot pop from an empty stack!\n";
            }
        }
        else if (3 == userSelection) 
        {
            if (!stack.isEmpty())
            {
                cout << "Value at the top of the stack is: " << stack.peek() << "\n";
            }
            else
            {
                cout << "Cannot peek into an empty stack!\n";
            }
        }
        else if (4 == userSelection) 
        {
            stack.traverseStack();
        }        
        else if (5 == userSelection) 
        {
            if (stack.isEmpty())
            {
                cout << "Stack is empty\n";
            }
            else
            {
                cout << "Stack is not empty\n";
            }
        }
        else if (6 == userSelection) 
        {
            exit(0);
        }
    }
    return 0;
}

