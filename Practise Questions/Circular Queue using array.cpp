#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int arr[5];
    int front;
    int rear;
    int count;

public:

    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Enqueue
    void enqueue(int x)
    {
        if (count == 5)
        {
            cout << "OVERFLOW" << endl;
            return;
        }

        rear = (rear + 1) % 5;
        arr[rear] = x;
        count++;
    }

    // Dequeue
    void dequeue()
    {
        if (count == 0)
        {
            cout << "UNDERFLOW" << endl;
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        front = (front + 1) % 5;
        count--;
    }

    // Display
    void display()
    {
        if (count == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = 0; i < count; i++)
        {
            cout << arr[(front + i) % 5] << " ";
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
