#include "List.h"
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

List::List() {}

// ---------------------------------------------------------------------------
// std::list<T>  — doubly linked list
//   - Each element stores a pointer to the previous AND next element.
//   - O(1) insert/erase at ANY position (once you have an iterator).
//   - NO random access — list[3] does NOT compile.
//   - Bidirectional iterators: supports ++, -- but NOT + n or [ ].
//   - More memory overhead per element than vector (two extra pointers).
//   - Use when you frequently insert/erase in the middle and don't need
//     random access (e.g., LRU cache, task lists, adjacency lists).
// ---------------------------------------------------------------------------
void List::demo()
{
    cout << "\n========== std::list ==========\n";

    // --- Construction ---
    list<int> lst = {30, 10, 50, 20, 40};

    // --- Insert at both ends (O(1)) ---
    lst.push_front(0);   // [0, 30, 10, 50, 20, 40]
    lst.push_back(60);   // [0, 30, 10, 50, 20, 40, 60]
    cout << "After push_front(0) + push_back(60): ";
    for (int v : lst) cout << v << " ";
    cout << "\n";

    // --- Remove at both ends (O(1)) ---
    lst.pop_front();     // removes 0
    lst.pop_back();      // removes 60
    cout << "After pop_front + pop_back:           ";
    for (int v : lst) cout << v << " ";
    cout << "\n";

    // --- Element access (only front/back — no operator[]) ---
    cout << "front() : " << lst.front() << "\n";
    cout << "back()  : " << lst.back()  << "\n";
    cout << "size()  : " << lst.size()  << "\n";

    // --- Insert / erase in the middle (O(1) given iterator, O(n) to find) ---
    auto it = lst.begin();
    advance(it, 2);          // move iterator 2 steps forward (O(n))
    lst.insert(it, 99);      // insert 99 before position 2
    cout << "After insert(99) at position 2: ";
    for (int v : lst) cout << v << " ";
    cout << "\n";

    it = lst.begin();
    advance(it, 2);
    lst.erase(it);           // erase element at position 2
    cout << "After erase at position 2:      ";
    for (int v : lst) cout << v << " ";
    cout << "\n";

    // --- Remove by value ---
    lst.push_back(10);       // add a duplicate
    cout << "Before remove(10): ";
    for (int v : lst) cout << v << " ";
    cout << "\n";
    lst.remove(10);          // removes ALL occurrences of 10
    cout << "After remove(10):  ";
    for (int v : lst) cout << v << " ";
    cout << "\n";

    // --- List-specific algorithms (more efficient than std:: versions) ---
    lst.sort();              // O(n log n) merge sort — std::sort doesn't work
                             // on list because it needs random-access iterators
    cout << "After sort(): ";
    for (int v : lst) cout << v << " ";
    cout << "\n";

    lst.reverse();           // O(n) — reverses the list in-place
    cout << "After reverse(): ";
    for (int v : lst) cout << v << " ";
    cout << "\n";

    // --- Iterators: Bidirectional (++ and -- work, but NOT + n) ---
    cout << "\nForward iteration (begin/end):\n  ";
    for (auto it2 = lst.begin(); it2 != lst.end(); ++it2)
        cout << *it2 << " ";
    cout << "\n";

    cout << "Reverse iteration (rbegin/rend):\n  ";
    for (auto it2 = lst.rbegin(); it2 != lst.rend(); ++it2)
        cout << *it2 << " ";
    cout << "\n";

    // --- splice: move elements from one list to another (O(1)) ---
    list<int> other = {100, 200};
    auto pos = lst.begin();
    advance(pos, 1);                    // point to second element
    lst.splice(pos, other);             // move all of 'other' into 'lst' at pos
    cout << "After splice (inserted {100,200} at pos 1): ";
    for (int v : lst) cout << v << " ";
    cout << "\n";
}
