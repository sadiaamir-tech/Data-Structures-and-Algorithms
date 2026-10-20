
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
        newNode->prev = temp;
    }

    void concatenate(DoublyLinkedList& M)
    {
        if (head == NULL)
        {
            head = M.head;
            return;
        }

        if (M.head == NULL)
            return;

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = M.head;
        M.head->prev = temp;
    }

    void sortDescending()
    {
        if (head == NULL)
            return;

        Node* i = head;

        while (i != NULL)
        {
            Node* j = i->next;

            while (j != NULL)
            {
                if (i->data < j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }

                j = j->next;
            }

            i = i->next;
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
    DoublyLinkedList L, M, N;

    for (int i = 2; i <= 10; i += 2)
    {
        L.insert(i);
    }

    for (int i = 1; i <= 9; i += 2)
    {
        M.insert(i);
    }

    // Copy L into N
    Node* temp = L.head;

    while (temp != NULL)
    {
        N.insert(temp->data);
        temp = temp->next;
    }

    // Concatenate M with N
    N.concatenate(M);

    cout << "List N before sorting: ";
    N.display();

    N.sortDescending();

    cout << "List N after sorting: ";
    N.display();

    return 0;
}

