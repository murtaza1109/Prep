#include "Array.h"
#include <array>
#include <algorithm>
#include <iostream>

using namespace std;

Array::Array() {}

// ---------------------------------------------------------------------------
// std::array<T, N>
//   - Fixed size determined at COMPILE TIME — cannot grow or shrink.
//   - Stored on the stack (no heap allocation).
//   - Supports random-access iterators (same as raw arrays but safer).
//   - Use when the size is constant and performance matters.
// ---------------------------------------------------------------------------
void Array::demo()
{
    cout << "\n========== std::array ==========\n";

    // --- Construction ---
    // Size N is part of the type: array<int,5> is a DIFFERENT type from array<int,6>
    array<int, 5> arr = {10, 20, 30, 40, 50};

    // --- Element access ---
    cout << "arr[0]    : " << arr[0]       << "\n"; // no bounds check
    cout << "arr.at(1) : " << arr.at(1)    << "\n"; // throws std::out_of_range
    cout << "front()   : " << arr.front()  << "\n"; // first element
    cout << "back()    : " << arr.back()   << "\n"; // last element
    cout << "data()    : " << arr.data()   << " (raw pointer to first element)\n";

    // --- Size ---
    cout << "size()    : " << arr.size()   << "\n";
    cout << "empty()   : " << arr.empty()  << "\n"; // always false for N>0

    // --- Modifiers ---
    arr.fill(99);   // set ALL elements to the same value
    cout << "After fill(99): ";
    for (int v : arr) cout << v << " ";
    cout << "\n";

    // Reset to something interesting for iterator demo
    array<int, 5> arr2 = {5, 3, 1, 4, 2};

    // --- Iterators ---
    // Random-access iterator: supports +, -, [], <, > operators
    cout << "\nForward iteration (begin/end):\n  ";
    for (auto it = arr2.begin(); it != arr2.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "Reverse iteration (rbegin/rend):\n  ";
    for (auto it = arr2.rbegin(); it != arr2.rend(); ++it)
        cout << *it << " ";
    cout << "\n";

    // Range-for (uses begin/end internally)
    cout << "Range-for loop:\n  ";
    for (int v : arr2) cout << v << " ";
    cout << "\n";

    // --- Works with std algorithms ---
    sort(arr2.begin(), arr2.end());
    cout << "After sort(): ";
    for (int v : arr2) cout << v << " ";
    cout << "\n";
}
