#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node (int d) {
        val = d;
        next = NULL;
    }
};

// Reverse the linked list
Node *reverse (Node *&head) {
    Node *curr = head, *prev = NULL, *next = NULL;
    while (curr) {
        next = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
} 

// Delete nodes having a greater value on the right
// Approach: Reverse → delete nodes smaller than max → reverse again
Node *deleteNodes (Node *&head) {
    if (!head || !head->next) return head;

    head = reverse(head); // Reverse to process from right to left

    Node *curr = head;
    int maxV = curr->val; // Track maximum value seen

    while (curr->next) {
        if (maxV > curr->next->val) curr->next = curr->next->next; // Remove node
        else {
            curr = curr->next;
            maxV = curr->val; // Update max
        }
    }
    return reverse(head); // Restore original order
}

// Print linked list
void print (Node *head) {
    Node *temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main () {
    int n; cin >> n;
    int val; cin >> val;
    Node *head = new Node(val);
    Node *temp = head;
    while (--n) {
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }
    head = deleteNodes(head);
    print(head);
    return 0;
}
