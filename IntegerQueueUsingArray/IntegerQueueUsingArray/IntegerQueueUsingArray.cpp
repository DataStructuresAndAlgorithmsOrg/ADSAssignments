//
//  main.cpp
//  integer_queue_using_array
//
//  Created by Venkata.bankapalli on 27/07/18.
//  Copyright © 2018 Bankapalli. All rights reserved.
//

#include <iostream>
#define MAX 10

using namespace std;

class Queue
{
    private:
        int front, rear;
        int a[MAX];
    public:
        Queue ()
        {
            front = -1;
            rear = -1;
        }
    
        void enqueue (int x)
        {
            if (rear == -1)
            {
                rear = rear + 1;
                a[rear] = x;
                front = front + 1;
            }
            else
            {
                if (rear == MAX-1)
                {
                    cout << "Queue Overflow! \n";
                }
                else
                {
                    rear = rear + 1;
                    a[rear] = x;
                }
            }
        }
    
        void dequeue ()
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
    cout << "Integer Queue Using Array \n";
    struct Queue queue;
    while (true)
    {
        int userSelection;
        cout << "Select the option for the operation that you want to perform on the queue...\n";
        cout << "1. Enqueue\t2. Dequeue\t3. Exit\t(Enter 1 or 2 or 3)\n";
        cin >> userSelection;
        switch (userSelection) {
            case 1:
                int valueToEnqueue;
                cout << "Enter a interger value to added into queue\n";
                cin >> valueToEnqueue;
                queue.enqueue(valueToEnqueue);
                queue.traverseQueue();
                break;
            case 2:
                if (!queue.isQueueEmpty())
                {
                    queue.dequeue();
                    queue.traverseQueue();
                }
                else
                {
                    cout << "Cannot remove from an empty queue!\n";
                }
                break;
            case 3:
                exit(0);
            default:
                break;
        }
    }
    return 0;
}
