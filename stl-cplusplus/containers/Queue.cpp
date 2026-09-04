#include "Queue.h"
#include <queue>
#include <iostream>

using namespace std;

Queue::Queue() {}

// ---------------------------------------------------------------------------
// std::queue<T>  — container ADAPTOR (FIFO — First In, First Out)
//   - Wraps an underlying container (default: std::deque).
//   - Exposes only FIFO operations — no random access, no iterators.
//   - 6 operations: push / pop / front / back / size / empty.
//   - pop() removes from the FRONT; push() adds to the BACK.
//   - Use cases: BFS (breadth-first search), task scheduling, print queues,
//     order processing, buffering data between producer and consumer.
//
// Template signature:
//   queue<T, Container>
//   default Container = deque<T>
// ---------------------------------------------------------------------------
void Queue::demo()
{
    cout << "\n========== std::queue ==========\n";

    queue<int> q;

    // --- push() — add to the BACK (O(1)) ---
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Pushed: 10, 20, 30, 40\n";

    // --- front() — oldest element (next to be removed) ---
    // --- back()  — newest element (most recently pushed) ---
    cout << "front() : " << q.front() << " (oldest — will leave first)\n";
    cout << "back()  : " << q.back()  << " (newest — will leave last)\n";
    cout << "size()  : " << q.size()  << "\n";

    // --- pop() — remove from the FRONT (O(1)), returns void ---
    // Always read front() BEFORE pop() if you need the value.
    cout << "\nProcessing in FIFO order:\n";
    while (!q.empty()) {
        cout << "  front=" << q.front() << "  →  pop\n";
        q.pop();
    }
    cout << "Queue is now empty: " << q.empty() << "\n";

    // --- stack vs queue side-by-side ---
    cout << "\n-- Stack (LIFO) vs Queue (FIFO) with same input {1,2,3} --\n";
    stack<int>  st;
    queue<int>  qu;
    for (int v : {1, 2, 3}) { st.push(v); qu.push(v); }

    cout << "Stack pops (LIFO): ";
    while (!st.empty()) { cout << st.top()   << " "; st.pop(); }
    cout << "\n";

    cout << "Queue pops (FIFO): ";
    while (!qu.empty()) { cout << qu.front() << " "; qu.pop(); }
    cout << "\n";

    // --- Practical example: BFS level-order simulation ---
    cout << "\n-- BFS order traversal simulation --\n";
    cout << "Tree:       1\n";
    cout << "          /   \\\n";
    cout << "         2     3\n";
    cout << "        / \\   / \\\n";
    cout << "       4   5 6   7\n\n";

    // Represent tree as array: node i has children 2i and 2i+1
    // BFS visits: 1, 2, 3, 4, 5, 6, 7
    queue<int> bfs;
    bfs.push(1);
    int nodeCount = 7;

    cout << "BFS visit order: ";
    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        cout << node << " ";
        int left  = 2 * node;
        int right = 2 * node + 1;
        if (left  <= nodeCount) bfs.push(left);
        if (right <= nodeCount) bfs.push(right);
    }
    cout << "\n";
}
