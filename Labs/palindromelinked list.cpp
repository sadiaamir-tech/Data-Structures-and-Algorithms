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

    bool isPalindrome()
    {
        // Original list ki copy
        Node* copy = NULL;
        Node* tail = NULL;

        Node* temp = head;

        while (temp != NULL)
        {
            Node* newNode = new Node(temp->data);

            if (copy == NULL)
            {
                copy = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }

            temp = temp->next;
        }

        // Original list reverse
        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL)
        {
            Node* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Dono compare
        Node* p1 = prev;
        Node* p2 = copy;

        while (p1 != NULL)
        {
            if (p1->data != p2->data)
            {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};

int main()
{
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(1);

    if (list.isPalindrome())
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}
