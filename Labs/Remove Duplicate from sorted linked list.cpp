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
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    void insert(int value)
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

    void deleteDuplicates()
    {
        Node* temp = head;

        while (temp != NULL && temp->next != NULL)
        {
            if (temp->data == temp->next->data)
            {
                Node* duplicate = temp->next;

                temp->next = temp->next->next;

                delete duplicate;
            }
            else
            {
                temp = temp->next;
            }
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

        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(3);

    cout << "Before removing duplicates: ";
    list.display();

    list.deleteDuplicates();

    cout << "After removing duplicates: ";
    list.display();

    return 0;
}
