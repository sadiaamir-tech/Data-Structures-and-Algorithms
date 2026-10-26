#include <iostream>
using namespace std;

class Deque
{
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:

    Deque()
    {
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) ||
               (front == rear + 1);
    }

    // Insert at Front
    void insertFront(int value)
    {
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        arr[front] = value;
    }

    // Insert at Rear
    void insertRear(int value)
    {
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;
    }

    // Delete at Front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    // Delete at Rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    // Display
    void display()
{
    if (isEmpty())
    {
        cout << "Deque is empty!" << endl;
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
};

int main()
{
    Deque d;

    d.insertRear(20);
    d.insertRear(30);
    d.insertFront(10);
    d.insertFront(5);

    cout << "Deque: ";
    d.display();

    d.deleteFront();

    cout << "After deleting front: ";
    d.display();

    d.deleteRear();

    cout << "After deleting rear: ";
    d.display();

    return 0;
}
