#include <iostream>
#include <stdlib.h>
using namespace std;

//Create a node structure
struct Node
{
	int data;
	Node *next;
};

class IntegerStackUsingLinkedList
{
	private:
		struct Node *top;

	public:
		IntegerStackUsingLinkedList ()
		{
			top = NULL;
		}

		void push (int elementToPush)
		{
			Node *temp = new Node();
			temp->data = elementToPush;
			if (top == NULL)
			{
				temp->next = NULL;
			}
			else
			{
				temp->next = top;
			}
			cout << temp->data;
			top=temp;
		}

		void pop ()
		{
			if (top != NULL)
			{
				Node *temp = top;
				top=temp->next;
				temp->next=NULL;
				cout << "Popped element is " << temp->data << "\n";
			}
			else
			{
				cout << "Stack is empty\n";
			}
		}

		void display ()
		{
			if (top != NULL)
			{
				Node *temp = top;
				while (temp->next != NULL)
				{
					cout << temp->data << "\t";
					temp=temp->next;
				}
				cout << temp->data << "\n";
			}
			else
			{
				cout << "Stack is empty\n";
			}

		}
};

int main () 
{
	cout << "This is a Stack implementation using Linked List to store integers\n";
	IntegerStackUsingLinkedList stack;

	while (1)
	{
		cout << "Select the operation that you want to perform\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Display\n";
		cout << "4. Exit Program\n";
		int selectedOperation;
		cin >> selectedOperation;
		switch (selectedOperation)
		{
			case 1:
				cout << "Selected operation is push\n";
				cout << "Enter interger to push into the stack\n";
				int elementToPush;
				cin >> elementToPush;
				stack.push(elementToPush);
				break;
			case 2:
				cout << "Selected operation is pop\n";
				stack.pop();				
				break;
			case 3:
				cout << "Selected operation is display\n";
				cout << "Elements in the stack are\n";
				stack.display();
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