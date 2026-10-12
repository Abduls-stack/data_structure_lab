#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
private:
    string pages[10];
    int top;

public:
    BrowserHistory() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
        } else {
            top++;
            pages[top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No browsing history!" << endl;
        } else {
            cout << "Back button pressed. Removed page: "
                 << pages[top] << endl;
            top--;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No page available." << endl;
        } else {
            cout << "Current TOP page: "
                 << pages[top] << endl;
        }
    }

    void displayHistory() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
        } else {
            cout << "Browsing History (TOP to bottom):" << endl;

            for (int i = top; i >= 0; i--) {
                cout << pages[i] << endl;
            }
        }
    }
};

int main() {
    BrowserHistory browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    browser.displayHistory();

    cout << "\n--- Pressing Back Button ---" << endl;
    browser.pop();

    cout << endl;
    browser.displayTop();

    cout << endl;
    browser.displayHistory();

    return 0;
}

