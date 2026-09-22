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
 
    void mergeSorted(LinkedList& l2) 
    { 
        Node* list1 = head; 
        Node* list2 = l2.head; 
 
        Node* dummy = new Node(0); 
        Node* temp = dummy; 
 
        while (list1 != NULL && list2 != NULL) 
        { 
            if (list1->data <= list2->data) 
            { 
                temp->next = list1; 
                list1 = list1->next; 
            } 
            else 
            { 
                temp->next = list2; 
                list2 = list2->next; 
            } 
 
            temp = temp->next; 
        } 
 
        if (list1 != NULL) 
        { 
            temp->next = list1; 
        } 
        else 
        { 
            temp->next = list2; 
        } 
 
        head = dummy->next; 
        delete dummy; 
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
    LinkedList l1; 
    LinkedList l2; 
 
    l1.insert(1); 
    l1.insert(2); 
    l1.insert(4); 
 
    l2.insert(1); 
    l2.insert(3); 
    l2.insert(4); 
 
    l1.mergeSorted(l2); 
 
    l1.display(); 
 
    return 0; 
} 
