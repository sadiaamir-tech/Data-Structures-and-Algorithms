#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node* head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    // Insert at Head
    void insertAtHead(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Insert at End
    void insertAtEnd(int value)
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
        newNode->prev = temp;
        newNode->next = NULL;
    }

    // Insert after a given node/value
    void insertInMiddle(int key, int value)
    {
        Node* temp = head;

        // Find the node containing key
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        // Key not found
        if (temp == NULL)
        {
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // Insert at a position
    void insertAtPosition(int position, int value)
    {
        if (position == 1)
        {
            insertAtHead(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // Display
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
    DoublyLinkedList list;

    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);

    list.insertAtEnd(40);

    list.insertInMiddle(20, 25);

    list.insertAtPosition(3, 15);

    list.display();

    return 0;
}
