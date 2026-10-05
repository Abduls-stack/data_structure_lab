#include <iostream>
#include <string>

using namespace std;

#define Nullptr NULL

class Node
{
public:
    string playerName;
    Node* next;

    Node(string name)
    {
        playerName = name;
        next = Nullptr;
    }
};

class Game
{
private:
    Node* head;

public:
    Game()
    {
        head = Nullptr;
    }

    void addPlayer(string name)
    {
        Node* newNode = new Node(name);

        if (head == Nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node* current = head;

            while (current->next != head)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->next = head;
        }
    }

    void displayTurns()
    {
        if (head == Nullptr)
        {
            cout << "No players available." << endl;
            return;
        }

        Node* current = head;

        cout << "Player Turns:" << endl;

        do
        {
            cout << current->playerName << endl;
            current = current->next;

        } while (current != head);

        cout << endl;
        cout << "After the last player, turn returns to: ";
        cout << current->playerName << endl;
    }
};

int main()
{
    Game game;

    game.addPlayer("Ali");
    game.addPlayer("Ahmed");
    game.addPlayer("Usman");
    game.addPlayer("Hamza");
    game.addPlayer("Bilal");

    game.displayTurns();

    return 0;
}

