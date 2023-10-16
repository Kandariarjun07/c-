#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    int info;
    node *next;

    node(int info)
    {
        this->info = info;
        this->next = NULL;
    }
};

void insertAtHead(node *&head, node *&tail, int data)
{

    // if no node is present, create new and point head and tail to it
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        // Create a new node with the provided data
        node *temp = new node(data);
        // Set the new node's next pointer to the current head
        temp->next = head;
        // Update the head to point to the new node
        head = temp;
    }
}
void reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
        return;

    node *prev = NULL;
    node *curr = head;
    node *next = head->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next != NULL)
            next = next->next;
    }
    head = prev;
}
void insertAtTail(node *&tail, int data)
{
    // Create a new node with the provided data
    node *temp = new node(data);
    // Set the current tail's next pointer to the new node
    tail->next = temp;
    // Update the tail to point to the new node
    tail = temp;
}
void insertAtMiddle(int pos, node *&head, node *&tail, int data)
{
    // Create a new node with the provided data
    node *newNode = new node(data);
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
    }
    else
    {
        int cnt = 1;
        node *temp = head;
        while (cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next == NULL)
        {
            // If the position is at the end, call insertAtTail
            insertAtTail(tail, data);
        }
        else
        {
        }
    }
}

void deleteNode(int pos, node *&head, node *&tail)
{
    node *prev = NULL;
    node *curr = head;
    if (pos == 1)
    {
        // If the position is 1, delete the head node
        prev = head;
        head = head->next;
        delete prev;
    }
    else
    {
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // if last element is being deleted, making sure to change tail
        if (curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL; // curr should not be a dangling pointer
        delete curr;
    }
}

void print(node *temp)
{
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
node *kReverse(node *head, int k)
{

    if (head == NULL)
    {
        return NULL;
    }

    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }
    return prev;
}

int main()
{
    node *head = NULL; // At the start, head and tail both points to null
    node *tail = NULL;

    insertAtMiddle(1, head, tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 11);
    insertAtTail(tail, 5);
    insertAtTail(tail, 19);
    insertAtTail(tail, 3);
    insertAtTail(tail, 13);
    insertAtTail(tail, 15);
    insertAtTail(tail, 17);
    insertAtTail(tail, 18);
    insertAtTail(tail, 6);
    print(head);
    reverse(head);
    print(head);
    return 0;
}
// 11
// 1 2 11 5 19 3 13 15 17 8 6
// 7
