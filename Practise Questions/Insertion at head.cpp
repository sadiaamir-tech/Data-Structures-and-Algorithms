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
        next = nullptr;
    }
};

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Insertion at Head
    Node* newNode = new Node(5);
    newNode->next = head;
    head = newNode;

    // Display
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";

    return 0;
}
