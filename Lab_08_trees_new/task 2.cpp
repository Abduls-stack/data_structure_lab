#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->name << " ";

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
    cout << endl;
}

int main() {
    Node* shop        = new Node("Shopping");
    Node* electronics = new Node("Electronics");
    Node* clothing    = new Node("Clothing");
    Node* mobiles     = new Node("Mobiles");
    Node* laptops     = new Node("Laptops");
    Node* men         = new Node("Men");
    Node* women       = new Node("Women");
    Node* accessories = new Node("Accessories");

    shop->left = electronics;
    shop->right = clothing;

    electronics->left = mobiles;
    electronics->right = laptops;

    clothing->left = men;
    clothing->right = women;

    mobiles->left = accessories;

    cout << "BFS Traversal of Categories:" << endl;
    bfs(shop);

    delete accessories;
    delete mobiles;
    delete laptops;
    delete electronics;
    delete men;
    delete women;
    delete clothing;
    delete shop;

    return 0;
}
