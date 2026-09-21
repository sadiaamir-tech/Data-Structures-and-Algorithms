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
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Merge Sort
    Node* sortList(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Middle find
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Second half
        Node* second = slow->next;
        slow->next = NULL;

        // Sort both parts
        Node* first = sortList(head);
        second = sortList(second);

        // Merge
        Node* dummy = new Node(0);
        Node* temp = dummy;

        while (first != NULL && second != NULL)
        {
            if (first->data < second->data)
            {
                temp->next = first;
                first = first->next;
            }
            else
            {
                temp->next = second;
                second = second->next;
            }

            temp = temp->next;
        }

        if (first != NULL)
            temp->next = first;
        else
            temp->next = second;

        return dummy->next;
    }

    void sort()
    {
        head = sortList(head);
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

    list.insert(4);
    list.insert(2);
    list.insert(1);
    list.insert(3);

    cout << "Before sorting: ";
    list.display();

    list.sort();

    cout << "\nAfter sorting: ";
    list.display();

    return 0;
}
