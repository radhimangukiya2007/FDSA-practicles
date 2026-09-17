#include <iostream>
using namespace std;

// Singly Circular Linked List
struct SNode {
    int data;
    SNode* next;
};

void displaySingly(SNode* head) {
    if (head == NULL) {
        cout << "Circle is empty!" << endl;
        return;
    }

    SNode* temp = head;

    while (true) {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == head) {
            break;
        }
    }

    cout << endl;
}

void joinSingly(SNode*& head, int value, int position) {
    SNode* newNode = new SNode();
    newNode->data = value;

    if (head == NULL) {
        if (position != 1) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        head = newNode;
        newNode->next = head;

        displaySingly(head);
        return;
    }

    if (position == 1) {
        SNode* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;

        displaySingly(head);
        return;
    }

    SNode* temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;

    displaySingly(head);
}

void leaveSingly(SNode*& head, int value) {
    if (head == NULL) {
        cout << "Circle is empty!" << endl;
        return;
    }

    SNode* current = head;
    SNode* previous = NULL;

    while (true) {
        if (current->data == value) {
            break;
        }

        previous = current;
        current = current->next;

        if (current == head) {
            cout << "Student not found!" << endl;
            return;
        }
    }

    if (current == head) {
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            SNode* last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;

            delete current;
        }
    } else {
        previous->next = current->next;
        delete current;
    }

    displaySingly(head);
}

// Doubly Circular Linked List
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

void displayDoubly(DNode* head) {
    if (head == NULL) {
        cout << "Circle is empty!" << endl;
        return;
    }

    DNode* temp = head;

    while (true) {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == head) {
            break;
        }
    }

    cout << endl;
}

void joinDoubly(DNode*& head, int value, int position) {
    DNode* newNode = new DNode();
    newNode->data = value;

    if (head == NULL) {
        if (position != 1) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        head = newNode;
        newNode->next = head;
        newNode->prev = head;

        displayDoubly(head);
        return;
    }

    if (position == 1) {
        DNode* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;

        displayDoubly(head);
        return;
    }

    DNode* temp = head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    displayDoubly(head);
}

void leaveDoubly(DNode*& head, int value) {
    if (head == NULL) {
        cout << "Circle is empty!" << endl;
        return;
    }

    DNode* current = head;

    while (true) {
        if (current->data == value) {
            break;
        }

        current = current->next;

        if (current == head) {
            cout << "Student not found!" << endl;
            return;
        }
    }

    if (current->next == current) {
        delete current;
        head = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head) {
            head = current->next;
        }

        delete current;
    }

    displayDoubly(head);
}

int main() {
    SNode* sHead = NULL;

    cout << "Singly Circular Linked List" << endl;

    joinSingly(sHead, 10, 1);
    joinSingly(sHead, 20, 2);
    joinSingly(sHead, 30, 3);
    joinSingly(sHead, 15, 2);

    cout << "After student leaves: ";
    leaveSingly(sHead, 20);

    cout << "Current circle: ";
    displaySingly(sHead);

    cout << endl;

    DNode* dHead = NULL;

    cout << "Doubly Circular Linked List" << endl;

    joinDoubly(dHead, 10, 1);
    joinDoubly(dHead, 20, 2);
    joinDoubly(dHead, 30, 3);
    joinDoubly(dHead, 15, 2);

    cout << "After student leaves: ";
    leaveDoubly(dHead, 20);

    cout << "Current circle: ";
    displayDoubly(dHead);

    return 0;
}