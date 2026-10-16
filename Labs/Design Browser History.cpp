
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string url;
    Node* prev;
    Node* next;

    Node(string value)
    {
        url = value;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory
{
public:
    Node* current;

    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    void visit(string url)
    {
        Node* newNode = new Node(url);

        current->next = NULL;

        newNode->prev = current;
        current->next = newNode;

        current = newNode;
    }

    string back(int steps)
    {
        while (steps > 0 && current->prev != NULL)
        {
            current = current->prev;
            steps--;
        }

        return current->url;
    }

    string forward(int steps)
    {
        while (steps > 0 && current->next != NULL)
        {
            current = current->next;
            steps--;
        }

        return current->url;
    }
};

int main()
{
    BrowserHistory b("leetcode.com");

    b.visit("google.com");
    b.visit("facebook.com");
    b.visit("youtube.com");

    cout << b.back(1) << endl;
    cout << b.back(1) << endl;
    cout << b.forward(1) << endl;

    b.visit("linkedin.com");

    cout << b.forward(2) << endl;
    cout << b.back(2) << endl;
    cout << b.back(7) << endl;

    return 0;
}

