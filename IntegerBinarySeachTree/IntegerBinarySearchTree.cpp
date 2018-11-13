#include <iostream>
#include <stdlib.h>
using namespace  std;

struct Node
{
	int data;
	Node *leftChild;
	Node *rightChild;
};

Node* createNode (int elementToInsert)
{
	Node* temp = new Node();
	temp->data=elementToInsert;
	temp->leftChild = temp->rightChild = NULL;
	return temp;
}

Node* insert (Node *root, int elementToInsert)
{
	if (root == NULL)
	{
		root = createNode(elementToInsert);
	}
	else if (root->data <= elementToInsert)
	{
		root->rightChild=insert(root->rightChild,elementToInsert);
	}
	else if (root->data > elementToInsert)
	{
		root->leftChild=insert(root->leftChild,elementToInsert);
	}
	return root;
}

void inOrderTraversal(Node *root)
{
	if (root != NULL)
	{
		inOrderTraversal(root->leftChild);
		cout << root->data << "\n";
		inOrderTraversal(root->rightChild);
	}
}

void preOrderTraversal(Node *root)
{
	if (root != NULL)
	{
		cout << root->data << "\n";
		preOrderTraversal(root->leftChild);
		preOrderTraversal(root->rightChild);
	}
}

void postOrderTraversal(Node *root)
{
	if (root != NULL)
	{
		postOrderTraversal(root->leftChild);
		postOrderTraversal(root->rightChild);
		cout << root->data << "\n";
	}
}

int heightOfTree(Node* root)
{
	int heightOfLeftSubTree, hightORightSubTree;
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		heightOfLeftSubTree=heightOfTree(root->leftChild);
		hightORightSubTree=heightOfTree(root->rightChild);
		if (heightOfLeftSubTree > hightORightSubTree)
		{
			return heightOfLeftSubTree+1;
		}
		else
		{
			return hightORightSubTree+1;
		}
	}
}

int main ()
{
	cout << "This is a Binary Search Tree implementation to store integers\n";

	Node *root = NULL;

	while (1)
	{
		cout << "Select the operation that you want to perform\n";
		cout << "1. Insert\n";
		cout << "2. InOrderTraversal\n";
		cout << "3. PreOrderTraversal\n";
		cout << "4. PostOrderTraversal\n";
		cout << "5. HeightOfTree\n";
		cout << "6. Exit Program\n"; 
		int selectedOperation;
		cin >> selectedOperation;
		switch (selectedOperation)
		{
			case 1:
				cout << "Selected operation is Insert\n";
				cout << "Enter interger to insert into the tree\n";
				int elementToInsert;
				cin >> elementToInsert;
				root = insert(root,elementToInsert);
				break;
			case 2:
				cout << "Selected operation is to perform inOrderTraversal of the tree\n";
				inOrderTraversal(root);
				break;
			case 3:
				cout << "Selected operation is to perform preOrderTraversal of the tree\n";
				preOrderTraversal(root);
				break;
			case 4:
				cout << "Selected operation is to perform preOrderTraversal of the tree\n";
				postOrderTraversal(root);
				break;
			case 5:
				cout << "Selected operation is to find the height of the tree\n";
				cout << "Height of the tree is: " << heightOfTree(root) << "\n";
				break;
			case 6:
				cout << "Selected operation is exit program\n";
				cout << "Exiting the program...\n";
				exit(1);
			default:
				cout << "Invalid operation selected\n";
				break;
		}
	}
}