#include "PriorityQueue.h"
#include <queue>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

PriorityQueue::PriorityQueue() {}

// ---------------------------------------------------------------------------
// std::priority_queue<T>  — container ADAPTOR (wraps another container)
//   - Internally uses std::vector + heap algorithms by default.
//   - Guarantees the highest-priority element is always at the TOP.
//   - Default: MAX-heap  → largest value has highest priority.
//   - All operations are O(log n) except top() which is O(1).
//   - NO iterators exposed — you can only see and remove the top element.
//   - Use cases: task scheduling, Dijkstra's algorithm, event simulation.
//
// Template signature:
//   priority_queue<T, Container, Comparator>
//   default Container  = vector<T>
//   default Comparator = less<T>   → MAX-heap
// ---------------------------------------------------------------------------
void PriorityQueue::demo()
{
    cout << "\n========== std::priority_queue ==========\n";

    // --- MAX-heap (default) ---
    cout << "-- MAX-heap (default, largest on top) --\n";
    priority_queue<int> maxPQ;
    maxPQ.push(30);
    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(20);
    maxPQ.push(40);

    cout << "top() = " << maxPQ.top() << " (always the maximum)\n";
    cout << "Popping in order: ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();   // removes the top element
    }
    cout << "\n";

    // --- MIN-heap (custom comparator) ---
    // Use greater<T> to flip the comparison → smallest is now on top
    cout << "\n-- MIN-heap (greater<int> comparator, smallest on top) --\n";
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);
    minPQ.push(40);

    cout << "top() = " << minPQ.top() << " (always the minimum)\n";
    cout << "Popping in order: ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << "\n";

    // --- size / empty ---
    priority_queue<int> pq2;
    cout << "\nempty() before push: " << pq2.empty() << "\n";
    pq2.push(5);
    cout << "size() after one push: " << pq2.size() << "\n";

    // --- Why no iterators? ---
    // priority_queue is a HEAP — the internal order is not the sorted order.
    // Exposing iterators would allow breaking the heap invariant.
    // If you need to iterate, use std::vector + make_heap, or std::multiset.
}
