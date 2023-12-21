#include <iostream>

#include "chain.h"


Node::Node() {
    data = 0;
    next = nullptr;
    prev = nullptr;
}

Node::Node(int data_) {
    data = data_;
    next = nullptr;
    prev = nullptr;
}

Chain::Chain() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void Chain::Insert(int data) {
    Node *toInsert = new Node(data);

    if (length == 0) {
        head = toInsert;
        tail = toInsert;
    } else {
        tail->next = toInsert;
        toInsert->prev = tail;
        tail = tail->next;
    }

    length++;
}

/*
*  Mix function: 
*  Splits an even-length linked list into two, then mixes the two lists back to front
*  Example: 
*   Input:  1 <-> 2 <-> 3 <-> 11 <-> 12 <-> 13
*   Output: 2 <-> 13 <-> 2 <-> 12 <-> 1 <-> 11
*/
void Chain::Mix() {
    // base case
    if (length == 0 || length & 1 == 1) return;
    // traverse to middle node
    Node *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // split list into two lists
    Node *prev = slow->prev;
    prev->next = nullptr;
    slow->prev = nullptr;

    Node *curr1 = head, *curr2 = slow;
    // reassign tail pointer
    tail = curr2;
    // traversing from back to front
    Node *next2 = curr2->next;
    while (curr2) {
        Node *next1 = curr1->next;
        curr2->prev = curr1;
        curr1->next = curr2;
        curr2 = next2;
        if (curr2) {
            next2 = curr2->next;
            curr1->prev = curr2;
            curr2->next = curr1;
            curr1 = next1;
        }
    }
    // reassingn head pointer
    head = curr1;
    // reset head and tail pointers
    head->prev = nullptr;
    tail->next = nullptr;
}

void Chain::PrintChain() {
    Node *curr = head;
    cout << "Forward: ";
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    curr = tail;
    cout << "Backward: ";
    while (curr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}
