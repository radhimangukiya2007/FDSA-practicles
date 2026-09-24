#include <iostream>
using namespace std;

class Stack
{
private:
    int *stack;
    int top;
    int capacity;

public:
    Stack(int n)
    {
        capacity = n;
        stack = new int[n];
        top = -1;
    }

    void push(int tray)
    {
        if (top == capacity - 1)
        {
            cout << "Error: Stack is FULL. Cannot place tray "
                 << tray << endl;
            return;
        }

        top++;
        stack[top] = tray;

        cout << "Placed tray: " << tray << endl;
        printTop();
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Error: Stack is EMPTY. Cannot take tray."
                 << endl;
            return;
        }

        cout << "Taken tray: " << stack[top] << endl;
        top--;

        printTop();
    }

    void printTop()
    {
        if (top == -1)
            cout << "Current top: EMPTY" << endl;
        else
            cout << "Current top: " << stack[top] << endl;
    }

    ~Stack()
    {
        delete[] stack;
    }
};

int main()
{
    int n;
    cout << "Enter stack capacity: ";
    cin >> n;

    Stack s(n);

    int choice, tray;

    while (true)
    {
        cout << "\n1. Place tray (Push)"
             << "\n2. Take tray (Pop)"
             << "\n3. Exit"
             << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter tray number: ";
            cin >> tray;
            s.push(tray);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}