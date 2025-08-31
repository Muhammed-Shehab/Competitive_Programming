#include <bits/stdc++.h>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Merge two sorted linked lists into one sorted list
// Do not modify main
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);       // dummy node to simplify edge cases
    ListNode* tail = &dummy; // points to last node in merged list

    // Merge while both lists have nodes
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;  // append l1 node
            l1 = l1->next;
        } else {
            tail->next = l2;  // append l2 node
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Append remaining nodes (if any)
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Helper function to create a linked list from array
ListNode* createList(int values[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int values1[n];
    for (int i = 0; i < n; i++) {
        cin >> values1[i];
    }

    int m;
    cin >> m;

    int values2[m];
    for (int i = 0; i < m; i++) {
        cin >> values2[i];
    }

    ListNode* l1 = createList(values1, n);
    ListNode* l2 = createList(values2, m);

    ListNode* merged = mergeTwoLists(l1, l2);
    printList(merged);

    return 0;
}
