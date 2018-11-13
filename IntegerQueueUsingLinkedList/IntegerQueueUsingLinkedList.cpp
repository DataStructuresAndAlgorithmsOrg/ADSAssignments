#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node 
{
	int data;
	Node *next;
};

class IntegerQueueUsingLinkedList
{
	private:
		Node *head, *tail;
	public:
		IntegerQueueUsingLinkedList () 
		{
			head = NULL;
			tail = NULL;
		}
		void enqueue(int elementToEnqueue)
		{
			Node *temp = new Node();
			temp->data=elementToEnqueue;
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
	cout << "This is a Queue implementation using Linked List to store integers\n";
	IntegerQueueUsingLinkedList queue;

	while (1)
	{
		cout << "Select the operation that you want to perform\n";
		cout << "1. Enqueue\n";
		cout << "2. Dequeue\n";
		cout << "3. Display\n";
		cout << "4. Exit Program\n";
		int selectedOperation;
		cin >> selectedOperation;
		switch (selectedOperation)
		{
			case 1:
				cout << "Selected operation is Enqueue\n";
				cout << "Enter interger to enqueue into the queue\n";
				int elementToEnqueue;
				cin >> elementToEnqueue;
				queue.enqueue(elementToEnqueue);
				break;
			case 2:
				cout << "Selected operation is Dequeue\n";
				queue.dequeue();				
				break;
			case 3:
				cout << "Selected operation is display\n";
				queue.display();
				break;
			case 4:
				cout << "Selected operation is exit program\n";
				cout << "Exiting the program...\n";
				exit(1);
			default:
				cout << "Invalid operation selected\n";
				break;
		}
	}
	return 0;
}