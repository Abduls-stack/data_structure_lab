
#include <iostream>
#include <string>
using namespace std;

class RestaurantStack {
private:
    struct Node {
        string orderID;
        Node* next;
    };

    Node* top;

public:
    RestaurantStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node;
        newNode->orderID = id;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "No orders available!" << endl;
        } else {
            Node* temp = top;

            cout << "Processed order: "
                 << top->orderID << endl;

            top = top->next;
            delete temp;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "No order available." << endl;
        } else {
            cout << "Current TOP order: "
                 << top->orderID << endl;
        }
    }

    void displayOrders() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Orders (TOP to bottom):" << endl;

        Node* current = top;

        while (current != NULL) {
            cout << current->orderID << endl;
            current = current->next;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }

    ~RestaurantStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    RestaurantStack restaurant;

    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    restaurant.displayOrders();

    cout << "\n--- Processing Orders ---" << endl;
    restaurant.pop();
    restaurant.pop();

    cout << endl;
    restaurant.displayTop();

    cout << "\nRemaining Orders:" << endl;
    restaurant.displayOrders();

    cout << "\nChecking Stack:" << endl;

    if (restaurant.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}

