#include <iostream>
using namespace std;

class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int t) {
        token = t;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

void updateHeight(Node* n) {
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* root, int token) {
    if (root == NULL)
        return new Node(token);

    if (token < root->token)
        root->left = insert(root->left, token);
    else if (token > root->token)
        root->right = insert(root->right, token);
    else
        return root;

    updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && token < root->left->token) {
        cout << "LL case at " << root->token << " -> Right Rotation" << endl;
        return rightRotate(root);
    }

    if (balance < -1 && token > root->right->token) {
        cout << "RR case at " << root->token << " -> Left Rotation" << endl;
        return leftRotate(root);
    }

    if (balance > 1 && token > root->left->token) {
        cout << "LR case at " << root->token << " -> Left then Right Rotation" << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && token < root->right->token) {
        cout << "RL case at " << root->token << " -> Right then Left Rotation" << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->token << " ";
    inorder(root->right);
}

void displayDetails(Node* root) {
    if (root == NULL)
        return;
    displayDetails(root->left);
    cout << "Token " << root->token << " | Height " << root->height
         << " | Balance Factor " << getBalance(root) << endl;
    displayDetails(root->right);
}

void printTree(Node* root, int level) {
    if (root == NULL)
        return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "    ";
    cout << root->token << endl;
    printTree(root->left, level + 1);
}

void deleteTree(Node* root) {
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = NULL;
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};
    int n = 7;

    for (int i = 0; i < n; i++) {
        cout << "Inserting " << tokens[i] << endl;
        root = insert(root, tokens[i]);
    }

    cout << endl << "In-order Traversal: ";
    inorder(root);
    cout << endl << endl;

    displayDetails(root);

    cout << endl << "Final Balanced Tree (rotated left, root on the left):" << endl;
    printTree(root, 0);

    deleteTree(root);
    return 0;
}
