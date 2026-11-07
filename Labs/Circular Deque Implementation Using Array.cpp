#include <iostream>
using namespace std;

class MyCircularDeque {
private:
    int arr[1000];
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        front = -1;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularDeque myCircularDeque(3);

    cout << boolalpha;

    cout << myCircularDeque.insertLast(1) << endl;
    cout << myCircularDeque.insertLast(2) << endl;
    cout << myCircularDeque.insertFront(3) << endl;
    cout << myCircularDeque.insertFront(4) << endl;

    cout << myCircularDeque.getRear() << endl;

    cout << myCircularDeque.isFull() << endl;

    cout << myCircularDeque.deleteLast() << endl;

    cout << myCircularDeque.insertFront(4) << endl;

    cout << myCircularDeque.getFront() << endl;

    return 0;
}
