#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

// Reverse a linked list starting from head
ListNode *reverse(ListNode *&head) {
    ListNode *next = NULL, *prev = NULL, *curr = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check if linked list is a palindrome
// Time Complexity: O(n), Space Complexity: O(1)
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Find middle using fast and slow pointers
    ListNode *fst = head, *slow = head;
    while (fst && fst->next) {
        fst = fst->next->next;
        slow = slow->next;
    }

    // Reverse second half of the list
    ListNode *f = head;
    ListNode *s = reverse(slow);

    // Compare both halves
    while (s) {
        if (f->val != s->val) return false;
        s = s->next;
        f = f->next;
    }

    return true;
}

// Helper to create linked list from vector
ListNode* createLinkedList(vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    ListNode* head = createLinkedList(values);
    cout << (isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}
