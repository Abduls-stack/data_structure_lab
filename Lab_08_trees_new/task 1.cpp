#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    string role;
    Node* left;
    Node* right;

    Node(string n, string r) {
        name = n;
        role = r;
        left = NULL;
        right =NULL;
    }
};

void displayMember(Node* node) {
    if (node == NULL)
        return;

    cout << node->name << " (" << node->role << ")" << endl;

    cout << "   Left child  : ";
    if (node->left != NULL)
        cout << node->left->name << " (" << node->left->role << ")";
    else
        cout << "None";
    cout << endl;

    cout << "   Right child : ";
    if (node->right != NULL)
        cout << node->right->name << " (" << node->right->role << ")";
    else
        cout << "None";
    cout << endl << endl;
}

void displayTree(Node* root) {
    if (root == NULL)
        return;

    displayMember(root);
    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    Node* hod    = new Node("Dr. Ahmed",  "HOD");
    Node* coord1 = new Node("Dr. Sara",   "Coordinator");
    Node* coord2 = new Node("Dr. Ali",    "Coordinator");
    Node* fac1   = new Node("Mr. Bilal",  "Faculty");
    Node* fac2   = new Node("Ms. Hina",   "Faculty");
    Node* fac3   = new Node("Mr. Usman",  "Faculty");
    Node* fac4   = new Node("Ms. Ayesha", "Faculty");

    hod->left = coord1;
    hod->right = coord2;

    coord1->left = fac1;
    coord1->right = fac2;

    coord2->left = fac3;
    coord2->right = fac4;

    cout << " University Department Hierarchy \n\n";
    displayTree(hod);

    delete fac1;
    delete fac2;
    delete fac3;
    delete fac4;
    delete coord1;
    delete coord2;
    delete hod;

    return 0;
}
