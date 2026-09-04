#include "Deque.h"
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

Deque::Deque() {}

// ---------------------------------------------------------------------------
// std::deque<T>  (pronounced "deck")
//   - Elements can be added/removed efficiently at BOTH ends (O(1)).
//   - Random access is O(1) but with slightly higher constant than vector
//     because memory is split into fixed-size chunks (not one contiguous block).
//   - Insertion/removal in the middle is O(n).
//   - Use when you need fast push_front AND push_back (e.g., sliding window,
//     BFS queues, undo/redo history).
//   - std::stack and std::queue are built on top of deque by default.
// ---------------------------------------------------------------------------
void Deque::demo()
{
    cout << "\n========== std::deque ==========\n";

    deque<int> dq;

    // --- Insert at both ends ---
    dq.push_back(30);    // [30]
    dq.push_back(40);    // [30, 40]
    dq.push_front(20);   // [20, 30, 40]
    dq.push_front(10);   // [10, 20, 30, 40]
    cout << "After push_back/front: ";
    for (int v : dq) cout << v << " ";
    cout << "\n";

    // --- Remove at both ends ---
    dq.pop_front();  // removes 10 → [20, 30, 40]
    dq.pop_back();   // removes 40 → [20, 30]
    cout << "After pop_front + pop_back: ";
    for (int v : dq) cout << v << " ";
    cout << "\n";

    // --- Element access (random-access, same API as vector) ---
    deque<int> dq2 = {10, 20, 30, 40, 50};
    cout << "dq2[2]    : " << dq2[2]       << "\n";
    cout << "dq2.at(3) : " << dq2.at(3)    << "\n";
    cout << "front()   : " << dq2.front()  << "\n";
    cout << "back()    : " << dq2.back()   << "\n";
    cout << "size()    : " << dq2.size()   << "\n";

    // --- Insert / erase in the middle (O(n)) ---
    dq2.insert(dq2.begin() + 2, 99);  // [10, 20, 99, 30, 40, 50]
    cout << "After insert(99) at index 2: ";
    for (int v : dq2) cout << v << " ";
    cout << "\n";

    dq2.erase(dq2.begin() + 2);       // remove 99
    cout << "After erase at index 2:     ";
    for (int v : dq2) cout << v << " ";
    cout << "\n";

    // --- Iterators (random-access, same as vector) ---
    cout << "\nForward iteration:\n  ";
    for (auto it = dq2.begin(); it != dq2.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "Reverse iteration:\n  ";
    for (auto it = dq2.rbegin(); it != dq2.rend(); ++it)
        cout << *it << " ";
    cout << "\n";

    // --- Works with std algorithms ---
    sort(dq2.begin(), dq2.end());
    cout << "After sort(): ";
    for (int v : dq2) cout << v << " ";
    cout << "\n";
}
