#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insertion at Head
    void insertAtHead(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insertion at Tail
    void insertAtTail(int data)
    {
        Node* newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insertion in Middle (after a given key)
    void insertMiddle(int key, int data)
    {
        Node* curr = head;
        while (curr != nullptr && curr->data != key)
        {
            curr = curr->next;
        }
        if (curr == nullptr) return;

        Node* newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Deletion at Head
    void deleteHead()
    {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Deletion at Tail
    void deleteTail()
    {
        if (head == nullptr) return;

        // Agar sirf ek node hai
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Deletion in Middle (delete node after a given key)
    void deleteMiddle(int key)
    {
        Node* curr = head;
        while (curr != nullptr && curr->next != nullptr && curr->data != key)
        {
            curr = curr->next;
        }
        if (curr == nullptr || curr->next == nullptr)
		return;

        Node* delNode = curr->next;
        curr->next = delNode->next;
        delete delNode;
    }

    // Display
    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;

    // Insertions
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertMiddle(20, 25);

    cout << "Initial List: ";
    list.display();

    // Deletion at Head
    list.deleteHead();
    cout << "After Deletion at Head: ";
    list.display();

    // Deletion at Tail
    list.deleteTail();
    cout << "After Deletion at Tail: ";
    list.display();

    // Deletion in Middle (delete node after 20)
    list.deleteMiddle(20);
    cout << "After Deletion in Middle: ";
    list.display();

    return 0;
}
