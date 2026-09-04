#include "Vector.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

Vector::Vector() {}

// ---------------------------------------------------------------------------
// std::vector<T>
//   - Dynamically-sized array. Elements are CONTIGUOUS in memory.
//   - Supports random-access iterators.
//   - push_back / pop_back are O(1) amortised; insert/erase in the middle O(n).
//   - Key concept: size vs capacity.
//       size()     — number of elements currently stored.
//       capacity() — how many elements can fit before reallocation.
//   - Use when you need a dynamic array and mostly append to the end.
// ---------------------------------------------------------------------------
void Vector::demo()
{
    cout << "\n========== std::vector ==========\n";

    // --- Construction ---
    vector<int> v;                       // empty
    vector<int> v2(4, 7);               // {7, 7, 7, 7}  — size 4, all 7s
    vector<int> v3 = {1, 2, 3, 4, 5};  // initialiser-list

    // --- Appending & removing at the back (O(1) amortised) ---
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << "After push_back x3, size=" << v.size()
         << "  capacity=" << v.capacity() << "\n";

    v.pop_back();   // removes last element
    cout << "After pop_back,    size=" << v.size() << "\n";

    // --- Reserving capacity to avoid repeated reallocations ---
    v.reserve(10);  // allocate space for 10 without changing size
    cout << "After reserve(10), size=" << v.size()
         << "  capacity=" << v.capacity() << "\n";

    // --- Element access ---
    cout << "v3[0]    : " << v3[0]      << "\n"; // no bounds check
    cout << "v3.at(1) : " << v3.at(1)   << "\n"; // throws out_of_range
    cout << "front()  : " << v3.front() << "\n";
    cout << "back()   : " << v3.back()  << "\n";

    // --- Insert & erase in the middle (O(n) — shifts elements) ---
    auto it = v3.begin() + 2;          // iterator pointing to index 2
    v3.insert(it, 99);                 // insert 99 before index 2
    cout << "After insert(99) at index 2: ";
    for (int x : v3) cout << x << " ";
    cout << "\n";

    v3.erase(v3.begin() + 2);          // remove element at index 2
    cout << "After erase at index 2:     ";
    for (int x : v3) cout << x << " ";
    cout << "\n";

    // --- Iterators ---
    // Random-access: can jump by arbitrary offset, compare with </>
    cout << "\nForward (iterator):\n  ";
    for (auto it2 = v3.begin(); it2 != v3.end(); ++it2)
        cout << *it2 << " ";
    cout << "\n";

    cout << "Reverse (reverse_iterator):\n  ";
    for (auto it2 = v3.rbegin(); it2 != v3.rend(); ++it2)
        cout << *it2 << " ";
    cout << "\n";

    // const_iterator — read-only access (use when you must not modify)
    cout << "Const iteration (cbegin/cend):\n  ";
    for (auto it2 = v3.cbegin(); it2 != v3.cend(); ++it2)
        cout << *it2 << " ";
    cout << "\n";

    // --- Works with std algorithms ---
    sort(v3.begin(), v3.end(), greater<int>()); // sort descending
    cout << "After sort descending: ";
    for (int x : v3) cout << x << " ";
    cout << "\n";

    // --- Clearing ---
    v3.clear();     // size → 0, capacity unchanged
    cout << "After clear(), size=" << v3.size() << "\n";
}
