#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list node
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Detect and remove cycle in linked list using Floyd’s Tortoise and Hare algorithm
// Return true if cycle was present and removed, else false
bool floydCycleRemoval(Node *head)
{
    Node *f = head, *s = head;

    // Detect cycle
    while (f && f->next) {
        f = f->next->next; // fast pointer moves 2 steps
        s = s->next;       // slow pointer moves 1 step
        if (f == s) break; // cycle detected
    }

    if (!f || !f->next) return false; // no cycle

    // Find start of the cycle
    s = head;
    while (f->next != s->next) {
        f = f->next;
        s = s->next;
    }

    // Remove cycle
    f->next = NULL;
    return true;
}

/*
* Build linked list with possible cycle, print linked list
*/

void buildCycleList(Node *&head)
{
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1) { head = NULL; return; }

    head = new Node(x);
    hash[x] = head;
    Node *current = head;

    while (x != -1)
    {
        cin >> x;
        if (x == -1) break;
        if (hash.find(x) != hash.end()) {
            current->next = hash[x]; // create cycle
            return;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head)
{
    unordered_set<int> s;
    while (head != NULL)
    {
        if (s.find(head->data) != s.end())
        {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    buildCycleList(head);

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent)
        cout << "Cycle was present\n";
    else
        cout << "No cycle\n";

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}
