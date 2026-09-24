#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = nullptr;
    }
};

class BrowserHistory {
private:
    Node* top;

public:
    BrowserHistory(string firstPage) {
        top = new Node(firstPage);
    }

    
    void visit(string page) {
        Node* newNode = new Node(page);
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
        cout << "Current page: " << top->page << endl;
    }

    
    void back() {
        if (top->next == nullptr) {
            cout << "Error: No history left. "
                 << "Already on the first page." << endl;
            cout << "Current page: " << top->page << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        cout << "Back from: " << temp->page << endl;
        delete temp;

        cout << "Current page: " << top->page << endl;
    }

    ~BrowserHistory() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    string firstPage;

    cout << "Enter first page: ";
    cin >> firstPage;

    BrowserHistory browser(firstPage);

    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit page"
             << "\n2. Back"
             << "\n3. Exit"
             << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page: ";
                cin >> page;
                browser.visit(page);
                break;

            case 2:
                browser.back();
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}