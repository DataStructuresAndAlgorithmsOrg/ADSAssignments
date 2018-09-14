//
//  main.cpp
//  QueueOfStringsUsingArray
//
//  Created by Venkata.bankapalli on 27/07/18.
//  Copyright © 2018 Bankapalli. All rights reserved.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_LENGHT_OF_QUEUE 10
// Technically pneumonoultramicroscopicsilicovolcanoconiosis is the longest word in dictionary.
// It has 45 letters in it, so declaring the maximum length of each word in the stack to be 50 characters.
#define MAX_LENGTH_OF_EACH_WORD_IN_QUEUE 50

class Queue
{
    private:
        int front, rear;
        char a[MAX_LENGHT_OF_QUEUE][MAX_LENGTH_OF_EACH_WORD_IN_QUEUE];
    public:
        Queue ()
        {
            front = -1;
            rear = -1;
        }
    
        void enqueue (string inputStr)
        {
            if (rear == -1)
            {
                rear = rear + 1;
                strcpy(this->a[rear], inputStr.c_str());
                front = front + 1;
            }
            else
            {
                if (rear == MAX_LENGHT_OF_QUEUE-1)
                {
                    cout << "Queue Overflow! \n";
                }
                else
                {
                    rear = rear + 1;
                    strcpy(this->a[rear], inputStr.c_str());
                }
            }
        }
    
        char* dequeue ()
        {
            if (isQueueEmpty())
            {
                cout << "Queue Underflow! \n";
            }
            else
            {
                cout << "Element dequeued from front: " << a[front] << "\n";
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = front + 1;
                }
            }
        }
    
        void traverseQueue ()
        {
            if (!isQueueEmpty())
            {
                cout << "Elements in the queue: ";
                for (int i=front;i<=rear;i++)
                {
                    if (i == rear)
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
                cout << "Queue is empty! \n";
        }
    
        bool isQueueEmpty ()
        {
            if (front == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};


int main()
{
    cout << "Queue Of Strings Using Array \n";
    struct Queue queue;
    while (true)
    {
        int userSelection;
        cout << "Select the option for the operation that you want to perform on the queue...\n";
        cout << "1. Enqueue\t2. Dequeue\t3. Exit\t(Enter 1 or 2 or 3)\n";
        cin >> userSelection;
        if (1 == userSelection) 
        {
            string valueToEnqueue;
            cout << "Enter a word to be added into queue\n";
            cin >> valueToEnqueue;
            queue.enqueue(valueToEnqueue);
            queue.traverseQueue();
        }
        else if (2 == userSelection) 
        {
            if (!queue.isQueueEmpty())
            {
                queue.dequeue();
                queue.traverseQueue();
            }
            else
            {
                cout << "Cannot remove from an empty queue!\n";
            }
        }
        else if (3 == userSelection) 
        {
                exit(0);
        }
    }
    return 0;
}
