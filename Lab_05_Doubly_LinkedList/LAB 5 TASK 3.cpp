#include <iostream>
#include <string>

using namespace std;

#define Nullptr NULL

class Node
{
public:
    string imageName;
    Node* prev;
    Node* next;

    Node(string name)
    {
        imageName = name;
        prev = Nullptr;
        next = Nullptr;
    }
};

class ImageGallery
{
private:
    Node* head;
    Node* tail;

public:
    ImageGallery()
    {
        head = Nullptr;
        tail = Nullptr;
    }

    void addImage(string name)
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

        cout << "Images (First -> Last):" << endl;

        while (current != Nullptr)
        {
            cout << current->imageName << endl;
            current = current->next;
        }
    }

    void displayBackward()
    {
        Node* current = tail;

        cout << endl;
        cout << "Images (Last -> First):" << endl;

        while (current != Nullptr)
        {
            cout << current->imageName << endl;
            current = current->prev;
        }
    }
};

int main()
{
    ImageGallery gallery;

    gallery.addImage("Nature.jpg");
    gallery.addImage("Mountain.jpg");
    gallery.addImage("Beach.jpg");
    gallery.addImage("Sunset.jpg");
    gallery.addImage("City.jpg");

    gallery.displayForward();

    gallery.displayBackward();

    return 0;
}

