//
//  main.cpp
//  assignment4
//
//  Implementation of Single Linked List
//
//  Created by Venkata.bankapalli on 25/07/18.
//  Copyright © 2018 Bankapalli. All rights reserved.
//

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class SingleLinkedList
{
private:
    node *head, *tail;
public:
    SingleLinkedList ()
    {
        head=NULL;
        tail=NULL;
    }
    void insertAtBegining (int data)
    {
        node *temp = new node();
        temp->data = data;
        temp->next = NULL;
        
        //Linked List is still empty
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void insertAtEnd (int data)
    {
        node *temp = new node();
        temp->data = data;
        temp->next = NULL;
        
        //Linked List is still empty
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void traverseListFromHeadToTail ()
    {
        if (head == NULL)
        {
            cout << "Single Linked List is empty";
        }
        else
        {
            node *temp = head;
            while(temp != NULL)
            {
                if (temp->next == NULL)
                    cout << temp->data;
                else
                    cout << temp->data << ", ";

                temp = temp->next;
            }
            cout << "\n";
        }
    }
    int removeAtBegining ()
    {
        if (head == NULL)
        {
            cout << "Single Linked List is empty";
            return 0;
        }
        else
        {
            node *temp = head;
            head = temp->next;
            temp->next = NULL;
            int x = temp->data;
            delete temp;
            return x;
        }
    }
    int removeAtEnd ()
    {
        if (head == NULL)
        {
            cout << "Single Linked List is empty";
            return 0;
        }
        else
        {
            node *temp = head;
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            temp = temp->next;
            tail->next = NULL;
            int x = temp->data;
            delete temp;
            return x;
        }
    }
    
    int getLengthOfTheList ()
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            node *temp = head;
            int lengthOfList=1;
            while (temp->next != NULL)
            {
                lengthOfList = lengthOfList+1;
                temp = temp->next;
            }
            return lengthOfList;
        }
    }
    
    void insertAtGivenPosition (int data, int pos)
    {
        int lengthOfTheList = getLengthOfTheList ();
        if (pos > 0 && pos <= lengthOfTheList+1)
        {
            if (pos == 1)
            {
                insertAtBegining(data);
            }
            else if (pos == lengthOfTheList+1)
            {
                insertAtEnd(data);
            }
            else
            {
                node *temp = new node();
                temp->data = data;
                temp->next = NULL;

                node *temp1, *temp2;
                temp1 = head;
                temp2 = head;
                for (int i=1;i<=lengthOfTheList;i++)
                {
                    if (pos == i)
                    {
                        temp->next = temp1;
                        temp2->next = temp;
                        break;
                    }
                    else
                    {
                        temp2 = temp1;
                        temp1 = temp1->next;
                    }
                }
            }
        }
        else
        {
            cout << "Given position is out of range in the linked list" << "\n";
        }
    }
};

int main()
{
    cout << "Single Linked List!\n";
    SingleLinkedList singleLinkedList;
    
    //Insert elements at the begining of the linked list
    singleLinkedList.insertAtBegining(1);
    singleLinkedList.insertAtBegining(2);

    //Length of list
    cout << "Length of list: " << singleLinkedList.getLengthOfTheList() << "\n";

    //Traverse the linked list
    singleLinkedList.traverseListFromHeadToTail();

    //Insert elements at the ending of the linked list
    singleLinkedList.insertAtEnd(3);
    singleLinkedList.insertAtEnd(4);

    //Length of list
    cout << "Length of list: " << singleLinkedList.getLengthOfTheList() << "\n";

    //Traverse the linked list
    singleLinkedList.traverseListFromHeadToTail();

    //Remove element at the ending of the linked list
    cout << "Last element removed from list: " << singleLinkedList.removeAtEnd() << "\n";
    
    //Remove element at the ending of the linked list
    cout << "Last element removed from list: " << singleLinkedList.removeAtEnd() << "\n";

    //Length of list
    cout << "Length of list: " << singleLinkedList.getLengthOfTheList() << "\n";

    //Traverse the linked list
    singleLinkedList.traverseListFromHeadToTail();
    
    //Insert elements at the ending of the linked list
    singleLinkedList.insertAtEnd(5);
    singleLinkedList.insertAtEnd(6);
    singleLinkedList.insertAtEnd(7);
    singleLinkedList.insertAtEnd(8);

    //Length of list
    cout << "Length of list: " << singleLinkedList.getLengthOfTheList() << "\n";

    //Traverse the linked list
    singleLinkedList.traverseListFromHeadToTail();

    //Remove element at the begining of the linked list
    cout << "First element removed from list: " << singleLinkedList.removeAtBegining() << "\n";
    
    //Remove element at the begining of the linked list
    cout << "First element removed from list: " << singleLinkedList.removeAtBegining() << "\n";
    
    //Length of list
    cout << "Length of list: " << singleLinkedList.getLengthOfTheList() << "\n";

    //Traverse the linked list
    singleLinkedList.traverseListFromHeadToTail();

    //Insert elements at a given position in linked list
    singleLinkedList.insertAtGivenPosition (9,2);
    
    //Traverse the linked list
    singleLinkedList.traverseListFromHeadToTail();

    cout << "\n";
    return 0;
}
