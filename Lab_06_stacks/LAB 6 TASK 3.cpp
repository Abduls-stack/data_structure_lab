#include <iostream>
#include <string>
using namespace std;

class HospitalStack {
private:
    struct Node {
        string patientID;
        Node* next;
    };

    Node* top;

public:
    HospitalStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node;
        newNode->patientID = id;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "No patient requests available!" << endl;
        } else {
            Node* temp = top;

            cout << "Handled patient request: "
                 << top->patientID << endl;

            top = top->next;
            delete temp;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "No request available." << endl;
        } else {
            cout << "Current TOP request: "
                 << top->patientID << endl;
        }
    }

    void displayRequests() {
        if (top == NULL) {
            cout << "No patient requests in the stack." << endl;
            return;
        }

        cout << "Patient Requests (TOP to bottom):" << endl;

        Node* current = top;

        while (current != NULL) {
            cout << current->patientID << endl;
            current = current->next;
        }
    }

    ~HospitalStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    HospitalStack hospital;

    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    hospital.displayRequests();

    cout << "\n--- Handling Emergency Request ---" << endl;
    hospital.pop();

    cout << endl;
    hospital.displayTop();

    cout << "\nRemaining Requests:" << endl;
    hospital.displayRequests();

    return 0;
}


