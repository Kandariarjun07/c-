#include<iostream>
using namespace std;

class node {
public:
    node* prev;
    node* next;
    int data;

    node(int d) {
        this->data = d;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node*& head, node*& tail, int d) {
    if (head == NULL) {
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else {
        node* temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(node*& head, node*& tail, int d) {

    if (head == NULL) {
        node* temp = new node(d);
        head = temp;
        tail = temp;
    }
    else {
        node* temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtMiddle(node*& head, node*& tail, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, tail, d);
    }
    else {
        int cnt = 1;
        node* temp = head;
        while (cnt < pos - 1) {
            if ((cnt < pos - 1) && (temp->next == NULL)) {
                cout << "Invalid !!" << endl;
                return;
            }
            temp = temp->next;
            cnt++;
        }
        if (temp->next == NULL) {
            insertAtTail(head, tail, d);
        }
        else {

            node* newNode = new node(d);
            temp->next->prev = newNode;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;

        }
    }
}

void deleteNode(node*& head, node*& tail, int pos) {

}

void print(node*& head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {

    node* head = NULL;
    node* tail = NULL;

    insertAtMiddle(head, tail, 1, 9);
    insertAtMiddle(head, tail, 2, 8);
    insertAtMiddle(head, tail, 3, 6);
    insertAtMiddle(head, tail, 4, 5);
    insertAtMiddle(head, tail, 0, 7);
    insertAtMiddle(head, tail, 7, 100);
    print(head);
    return 0;
}