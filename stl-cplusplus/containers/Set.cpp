#include "Set.h"
#include <set>
#include <iostream>

using namespace std;

Set::Set() {}

// ---------------------------------------------------------------------------
// std::set<T>  — ordered collection of unique values
//   - Backed by a Red-Black Tree (same as std::map, but only keys, no values).
//   - Elements are ALWAYS SORTED (ascending by default).
//   - Duplicates are SILENTLY IGNORED on insert.
//   - All operations: O(log n).
//   - Bidirectional iterators; elements are immutable through iterators
//     (modifying a key would break the ordering invariant).
//   - Use for: membership testing, deduplication, maintaining a sorted unique set.
//   - Use std::unordered_set for O(1) average lookups (no order).
//   - Use std::multiset to allow duplicates.
// ---------------------------------------------------------------------------
void Set::demo()
{
    cout << "\n========== std::set ==========\n";

    // --- Construction ---
    set<int> s = {40, 10, 30, 10, 20, 30}; // duplicates are discarded
    cout << "Constructed from {40,10,30,10,20,30}, stored as: ";
    for (int v : s) cout << v << " ";  // always sorted: 10 20 30 40
    cout << "\n";

    // --- Insert (O(log n)) ---
    auto [it1, inserted1] = s.insert(25);   // returns pair<iterator, bool> (C++17)
    auto [it2, inserted2] = s.insert(10);   // duplicate — not inserted
    cout << "insert(25) succeeded : " << inserted1 << "\n";
    cout << "insert(10) succeeded : " << inserted2 << " (duplicate)\n";
    cout << "After inserts: ";
    for (int v : s) cout << v << " ";
    cout << "\n";

    // --- Lookup ---
    // find() — O(log n), returns end() if not found
    auto it = s.find(30);
    if (it != s.end())
        cout << "Found: " << *it << "\n";

    // count() — returns 1 (found) or 0 (not found) for std::set
    cout << "count(30): " << s.count(30) << "\n";
    cout << "count(99): " << s.count(99) << "\n";

    // contains() — C++20, cleaner
    // cout << "contains(30): " << s.contains(30) << "\n";

    // --- Erase ---
    s.erase(10);            // erase by value
    cout << "After erase(10): ";
    for (int v : s) cout << v << " ";
    cout << "\n";

    auto it3 = s.find(40);
    s.erase(it3);           // erase by iterator
    cout << "After erase(iterator to 40): ";
    for (int v : s) cout << v << " ";
    cout << "\n";

    // --- Size / empty ---
    cout << "size()  : " << s.size()  << "\n";
    cout << "empty() : " << s.empty() << "\n";

    // --- Iterators (bidirectional — no random access) ---
    cout << "\nForward iteration:\n  ";
    for (auto it4 = s.begin(); it4 != s.end(); ++it4)
        cout << *it4 << " ";
    cout << "\n";

    cout << "Reverse iteration:\n  ";
    for (auto it4 = s.rbegin(); it4 != s.rend(); ++it4)
        cout << *it4 << " ";
    cout << "\n";

    // --- Range queries (lower_bound / upper_bound — because set is sorted) ---
    set<int> big = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto lo = big.lower_bound(3);  // first element >= 3
    auto hi = big.upper_bound(7);  // first element >  7
    cout << "\nElements in range [3, 7]: ";
    for (auto it4 = lo; it4 != hi; ++it4)
        cout << *it4 << " ";
    cout << "\n";

    // --- multiset: allows duplicates ---
    multiset<int> ms = {1, 2, 2, 3, 3, 3};
    cout << "\nmultiset from {1,2,2,3,3,3}: ";
    for (int v : ms) cout << v << " ";
    cout << "\n";
    cout << "count(3) in multiset: " << ms.count(3) << "\n";
}
