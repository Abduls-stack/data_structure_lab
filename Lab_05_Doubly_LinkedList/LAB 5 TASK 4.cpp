#include <iostream>
#include <string>

using namespace std;

#define Nullptr NULL

class Node
{
public:
    string songName;
    Node* next;

    Node(string name)
    {
        songName = name;
        next = Nullptr;
    }
};

class MusicPlaylist
{
private:
    Node* head;

public:
    MusicPlaylist()
    {
        head = Nullptr;
    }

    void addSong(string name)
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

    void displaySongs()
    {
        Node* current = head;

        cout << "Playlist (All Songs Once):" << endl;

        do
        {
            cout << current->songName << endl;
            current = current->next;

        } while (current != head);
    }

    void playTwoRounds()
    {
        Node* current = head;

        cout << endl;
        cout << "Playing Playlist for 2 Rounds:" << endl;

        for (int round = 1; round <= 2; round++)
        {
            cout << endl;
            cout << "Round " << round << ":" << endl;

            for (int i = 1; i <= 5; i++)
            {
                cout << "Playing: " << current->songName << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    MusicPlaylist playlist;

    playlist.addSong("Perfect");
    playlist.addSong("Believer");
    playlist.addSong("Shape of You");
    playlist.addSong("Faded");
    playlist.addSong("Counting Stars");

    playlist.displaySongs();

    playlist.playTwoRounds();

    return 0;
}

