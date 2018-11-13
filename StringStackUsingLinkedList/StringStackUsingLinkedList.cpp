#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define MAX_LENGTH_OF_EACH_WORD_IN_STACK 50


//Create a node structure
struct Node
{
	char data[MAX_LENGTH_OF_EACH_WORD_IN_STACK];
	Node *next;
};

class StringStackUsingLinkedList
{
	private:
		struct Node *top;

	public:
		StringStackUsingLinkedList ()
		{
			top = NULL;
		}

		void push (string elementToPush)
		{
			Node *temp = new Node();
			strcpy(temp->data,elementToPush.c_str());
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
	cout << "This is a Stack implementation using Linked List to store strings\n";
	StringStackUsingLinkedList stack;

	while (1)
	{
		cout << "Select the operation that you want to perform\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Display\n";
		cout << "4. Exit Program\n";
		int selectedOperation;
		cin >> selectedOperation;
		if(1 == selectedOperation)
		{
			cout << "Selected operation is push\n";
			cout << "Enter string to push into the stack\n";
			string elementToPush;
			cin >> elementToPush;
			stack.push(elementToPush);
		}
		else if (2 == selectedOperation)
		{
			cout << "Selected operation is pop\n";
			stack.pop();				
		}
		else if (3 == selectedOperation)
		{
			cout << "Selected operation is display\n";
			cout << "Elements in the stack are\n";
			stack.display();
		}
		else if (4 == selectedOperation)
		{
			cout << "Selected operation is exit program\n";
			cout << "Exiting the program...\n";
			exit(0);
		}
		else
		{
			cout << "Invalid operation selected\n";
		}
	}
	return 0;
}