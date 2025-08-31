#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    int n; 
    cin >> n;  // Number of operations
    vector<queue<int>> roll(n + 1);  // Queues for each course
    queue<int> order;  // Queue to maintain order of courses with students

    char ch;
    cin >> ch;  // Operation type: 'E' for enqueue, 'D' for dequeue

    while (n--) {

        if (ch == 'E') {
            // Enqueue operation
            int course, rollNo;
            cin >> course >> rollNo;

            if (roll[course].empty()) 
                order.push(course);  // Add course to order if first student
            roll[course].push(rollNo);  // Add student to course queue
        }
        else {
            // Dequeue operation
            int front = order.front();  // Course at front
            cout << front << ' ' << roll[front].front() << endl;  // Print course and student
            roll[front].pop();  // Remove student

            if (roll[front].empty()) 
                order.pop();  // Remove course if no students left
        }
        cin >> ch;  // Read next operation
    }

    return 0;
}
