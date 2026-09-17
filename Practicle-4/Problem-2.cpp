#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

void display(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data << " ";

        temp = temp->next;
    }

    cout << endl;
}

void insertEnd(Node *&head, int value)
{

    Node *newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteValue(Node *&head, int value)
{

    // If queue is empty
    if (head == NULL)
    {

        cout << "Queue is empty!" << endl;
        return;
    }

    if (head->data == value)
    {

        Node *deleteNode = head;

        head = head->next;

        delete deleteNode;

        cout << "Patient deleted!" << endl;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL &&
           temp->next->data != value)
    {

        temp = temp->next;
    }

    if (temp->next == NULL)
    {

        cout << "Patient not found!" << endl;
        return;
    }

    Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;

    cout << "Patient deleted!" << endl;
}

void reversePrint(Node *head)
{

    if (head == NULL)
    {
        return;
    }

    reversePrint(head->next);

    cout << head->data << " ";
}

int main()
{

    Node *head = NULL;

    insertEnd(head, 101);
    insertEnd(head, 102);
    insertEnd(head, 103);
    insertEnd(head, 104);
    insertEnd(head, 105);

    cout << "Forward Queue: ";
    display(head);

    cout << "\nDeleting patient 103..." << endl;

    deleteValue(head, 103);

    cout << "Queue after deletion: ";
    display(head);

    cout << "\nReverse Queue: ";
    reversePrint(head);

    cout << endl;

    return 0;
}