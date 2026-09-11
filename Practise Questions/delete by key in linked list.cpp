#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insertion at Tail
    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete by Key
    void deleteByKey(int key) {
        if (head == nullptr) return;

        // Agar head node hi key hai
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Otherwise traverse karo
        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != key) {
            curr = curr->next;
        }

        // Agar key mila
        if (curr->next != nullptr) {
            Node* delNode = curr->next;
            curr->next = delNode->next;
            delete delNode;
        }
    }

    // Display
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Initial List: ";
    list.display();

    // Delete by Key
    list.deleteByKey(20);
    cout << "After deleting 20: ";
    list.display();

    list.deleteByKey(40);
    cout << "After deleting 40: ";
    list.display();

    list.deleteByKey(10);
    cout << "After deleting 10: ";
    list.display();

    return 0;
}

