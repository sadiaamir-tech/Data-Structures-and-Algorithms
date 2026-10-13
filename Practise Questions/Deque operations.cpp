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

class Deque
{
private:
    Node* front;
    Node* rear;

public:

    Deque()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    // Insert at Front
    void insertFront(int value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Insert at Rear
    void insertRear(int value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Delete at Front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete at Rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if (rear == NULL)
        {
            front = NULL;
        }
        else
        {
            rear->next = NULL;
        }

        delete temp;
    }

    // Display from Front
    void display()
    {
        Node* temp = front;

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
    Deque d;

    // Insert at Front
    d.insertFront(20);
    d.insertFront(10);

    // Insert at Rear
    d.insertRear(30);
    d.insertRear(40);

    cout << "Deque: ";
    d.display();

    // Delete at Front
    d.deleteFront();

    cout << "After deleting Front: ";
    d.display();

    // Delete at Rear
    d.deleteRear();

    cout << "After deleting Rear: ";
    d.display();

    return 0;
}
