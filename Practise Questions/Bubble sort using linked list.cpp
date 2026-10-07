#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;

public:

    LinkedList()
    {
        head = NULL;
    }

    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

   void bubbleSort()
{
    Node* current = head;

    while (current != NULL)
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                int value = temp->data;
                temp->data = temp->next->data;
                temp->next->data = value;
            }

            temp = temp->next;
        }

        current = current->next;
    }
}

    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList list;

    list.insertEnd(64);
    list.insertEnd(25);
    list.insertEnd(12);
    list.insertEnd(22);
    list.insertEnd(11);

    cout << "Before Sorting: ";
    list.display();

    list.bubbleSort();

    cout << "\nAfter Sorting: ";
    list.display();

    return 0;
}
