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
    Node* head = nullptr;   // initially list empty

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    // User se values input lo
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter value for node " << i+1 << ": ";
        cin >> val;

        Node* newNode = new Node(val);

        // Agar list empty hai to head newNode banega
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // Tail tak jao
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display linked list
    Node* temp = head;
    cout << "\nLinked List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}

