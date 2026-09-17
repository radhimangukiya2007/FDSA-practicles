#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->song << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertBeginning(Node*& head, string song) {
    Node* newNode = new Node();

    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    display(head);
}

void insertEnd(Node*& head, string song) {
    Node* newNode = new Node();

    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;

        display(head);
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;

    display(head);
}

void insertAfter(Node*& head, string afterSong, string song) {
    Node* temp = head;

    while (temp != NULL && temp->song != afterSong) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Song not found!" << endl;
        return;
    }

    Node* newNode = new Node();

    newNode->song = song;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    display(head);
}

void deleteFirst(Node*& head) {
    if (head == NULL) {
        cout << "Playlist is empty!" << endl;
        return;
    }

    Node* deleteNode = head;

    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete deleteNode;

    display(head);
}

int countSongs(Node* head) {
    int count = 0;

    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    Node* head = NULL;

    insertBeginning(head, "Song A");
    insertBeginning(head, "Song B");

    insertEnd(head, "Song C");
    insertEnd(head, "Song D");

    insertAfter(head, "Song B", "Song X");

    deleteFirst(head);

    cout << "Total songs: " << countSongs(head) << endl;

    cout << "Final playlist: ";
    display(head);

    return 0;
}