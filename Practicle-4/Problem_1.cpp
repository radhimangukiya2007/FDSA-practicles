#include <iostream>
using namespace std;

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

void insertBeginning(Node *&head, int value)
{

    Node *newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    cout << "After insertion at beginning: ";
    display(head);
}

void insertEnd(Node *&head, int value)
{

    Node *newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;

        cout << "After insertion at end: ";
        display(head);

        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "After insertion at end: ";
    display(head);
}

void insertPosition(Node *&head, int value, int position)
{

    if (position < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1)
    {

        insertBeginning(head, value);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *newNode = new Node();

    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "After insertion at position: ";
    display(head);
}

int main()
{

    Node *head = NULL;

    insertBeginning(head, 101);
    insertBeginning(head, 102);

    insertEnd(head, 103);
    insertEnd(head, 104);

    insertPosition(head, 105, 3);

    return 0;
}