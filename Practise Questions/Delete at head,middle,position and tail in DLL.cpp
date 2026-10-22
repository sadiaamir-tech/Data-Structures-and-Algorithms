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

    // Insert at Tail
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
    }

    // Delete from Head
    void deleteFromHead()
    {
        if (head == NULL)
        {
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
    }

    // Delete from End
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->prev != NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            head = NULL;
        }

        delete temp;
    }

    // Delete from Middle by value
    void deleteFromMiddle(int key)
    {
        Node* curr = head;

        while (curr != NULL && curr->data != key)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            return;
        }

        if (curr->prev == NULL)
        {
            deleteFromHead();
            return;
        }

        curr->prev->next = curr->next;

        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }

        delete curr;
    }

    // Delete at Position
    void deleteAtPosition(int position)
    {
        if (head == NULL)
        {
            return;
        }

        if (position == 1)
        {
            deleteFromHead();
            return;
        }

        Node* curr = head;

        for (int i = 1; i < position && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if (curr == NULL)
        {
            return;
        }

        curr->prev->next = curr->next;

        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }

        delete curr;
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

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original List: ";
    list.display();

    list.deleteFromHead();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteFromMiddle(20);
    list.display();

    list.deleteAtPosition(1);
    list.display();

    return 0;
}
