#include <iostream>
#include <string>
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

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->name << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->name << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->name << " ";
}

int main() {
    Node* root      = new Node("C:");
    Node* users     = new Node("Users");
    Node* programs  = new Node("Programs");
    Node* documents = new Node("Documents");
    Node* downloads = new Node("Downloads");
    Node* games     = new Node("Games");
    Node* office    = new Node("Office");

    root->left = users;
    root->right = programs;

    users->left = documents;
    users->right = downloads;

    programs->left = games;
    programs->right = office;

    cout << "Pre-order  (Root, Left, Right): ";
    preorder(root);
    cout << endl;

    cout << "In-order   (Left, Root, Right): ";
    inorder(root);
    cout << endl;

    cout << "Post-order (Left, Right, Root): ";
    postorder(root);
    cout << endl;

    delete documents;
    delete downloads;
    delete users;
    delete games;
    delete office;
    delete programs;
    delete root;

    return 0;
}
