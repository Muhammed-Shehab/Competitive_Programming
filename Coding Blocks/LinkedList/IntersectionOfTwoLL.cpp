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

// Find intersection node of two linked lists
// Uses two-pointer technique: traverse both lists, switching heads when reaching the end
// Time complexity: O(n + m), Space complexity: O(1)
Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    if (!l1 || !l2) return NULL;

    Node *p1 = l1, *p2 = l2;

    // Move pointers; when they meet, that's the intersection
    while (p1 != p2) {
        p1 = (p1 == NULL) ? l2 : p1->next;
        p2 = (p2 == NULL) ? l1 : p2->next;
    }

    return p1; // intersection node (or NULL if no intersection)
}

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    unordered_map<int, Node *> hash;
    Node *l1 = buildList(hash);

    Node *l2 = NULL;
    int x;
    cin >> x;
    l2 = new Node(x);
    Node *temp = l2;

    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            temp->next = hash[x]; // create intersection
            break;
        }
        Node *n = new Node(x);
        temp->next = n;
        temp = n;
    }

    cout << "L1 - ";
    printLinkedList(l1);
    cout << "L2 - ";
    printLinkedList(l2);

    Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
    cout << "Intersection at node with data = " << intersectionPoint->data << endl;

    return 0;
}
