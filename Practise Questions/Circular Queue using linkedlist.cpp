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

class CircularQueue
{
private:
    Node* front;
    Node* rear;

public:
    CircularQueue()
    {
        front = NULL;
        rear = NULL;
    }

    // Enqueue
    void enqueue(int x)
    {
        Node* n = new Node(x);

        if (front == NULL)
        {
            front = rear = n;
            rear->next = front;
        }
        else
        {
            rear->next = n;
            rear = n;
            rear->next = front;
        }
    }

    // Dequeue
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "UNDERFLOW" << endl;
            return;
        }

        Node* temp = front;

        cout << "Deleted: " << front->data << endl;

        // Only one node
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }

        delete temp;
    }

    // Display
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Queue: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != front);

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(40);

    q.display();

    return 0;
}
