#include <iostream>
#include <string>

using namespace std;

#define Nullptr NULL

class Node
{
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name)
    {
        website = name;
        prev = Nullptr;
        next = Nullptr;
    }
};

class BrowserHistory
{
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory()
    {
        head = Nullptr;
        tail = Nullptr;
    }

    void addWebsite(string name)
    {
        Node* newNode = new Node(name);

        if (head == Nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward()
    {
        Node* current = head;

        cout << "Browser History (First -> Last)" << endl;

        while (current != Nullptr)
        {
            cout << current->website << endl;
            current = current->next;
        }
    }

    void displayReverse()
    {
        Node* current = tail;

        cout << endl;
        cout << "Browser History (Last -> First)" << endl;

        while (current != Nullptr)
        {
            cout << current->website << endl;
            current = current->prev;
        }
    }
};

int main()
{
    BrowserHistory history;

    history.addWebsite("Google.com");
    history.addWebsite("YouTube.com");
    history.addWebsite("GitHub.com");
    history.addWebsite("Wikipedia.org");
    history.addWebsite("StackOverflow.com");

    history.displayForward();

    history.displayReverse();

    return 0;
}


