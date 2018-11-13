#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define MAX_LENGTH_OF_EACH_WORD_IN_STACK 50

struct Node 
{
	char data[MAX_LENGTH_OF_EACH_WORD_IN_STACK];
	Node *next;
};

class StringQueueUsingLinkedList
{
	private:
		Node *head, *tail;
	public:
		StringQueueUsingLinkedList () 
		{
			head = NULL;
			tail = NULL;
		}
		void enqueue(string elementToEnqueue)
		{
			Node *temp = new Node();
			strcpy(temp->data,elementToEnqueue.c_str());
			temp->next=NULL;
			if (tail != NULL)
			{
				tail->next=temp;
				tail=temp;
			}
			else
			{
				head = tail = temp;
			}
		}
		void dequeue()
		{
			if (head == NULL)
			{
				cout << "Queue is empty\n";
			}
			else
			{
				Node *temp = new Node();
				temp=head;
				head=head->next;
				temp->next=NULL;
				if (head == NULL)
				{
					tail = NULL;
				}
				cout << "Element dequeued is " << temp->data << "\n";
			}
		}
		void display()
		{
			if (head == NULL)
			{
				cout << "Queue is empty\n";
			}
			else
			{
				cout << "Elements in the queue are: ";				
				Node *temp = new Node();
				temp=head;
				while (temp != NULL)
				{
					cout << temp->data << "\t";
					temp=temp->next;
				}
				cout << "\n";
			}
		}
};

int main ()
{
	cout << "This is a Queue implementation using Linked List to store strings\n";
	StringQueueUsingLinkedList queue;

	while (1)
	{
		cout << "Select the operation that you want to perform\n";
		cout << "1. Enqueue\n";
		cout << "2. Dequeue\n";
		cout << "3. Display\n";
		cout << "4. Exit Program\n";
		int selectedOperation;
		cin >> selectedOperation;
		if(1 == selectedOperation)
		{
			cout << "Selected operation is Enqueue\n";
			cout << "Enter string to enqueue into the queue\n";
			string elementToEnqueue;
			cin >> elementToEnqueue;
			queue.enqueue(elementToEnqueue);
		}
		else if(2 == selectedOperation)
		{
				cout << "Selected operation is Dequeue\n";
				queue.dequeue();				
		}
		else if(3 == selectedOperation)
		{
			cout << "Selected operation is display\n";
			queue.display();
		}
		else if(4 == selectedOperation)
		{
				cout << "Selected operation is exit program\n";
				cout << "Exiting the program...\n";
				exit(1);
		}
		else
		{
			cout << "Invalid operation selected\n";
		}
	}
	return 0;
}