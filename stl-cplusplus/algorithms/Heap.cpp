#include "Heap.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

Heap::Heap() {}

// ---------------------------------------------------------------------------
// Heap Algorithms  (<algorithm>)
//
//  A "heap" in the STL sense is a binary max-heap stored in a flat array
//  (vector) so that v[0] is always the largest element.
//
//  std::make_heap     — rearrange range into a max-heap           O(n)
//  std::push_heap     — add element at end into existing heap     O(log n)
//  std::pop_heap      — move max to back, re-heapify [first, last-1) O(log n)
//  std::sort_heap     — sort a heap (destroys heap property)      O(n log n)
//  std::is_heap       — check if range satisfies heap invariant   O(n)
//  std::is_heap_until — first iterator where heap invariant breaks O(n)
//
//  Min-heap: pass greater<T>() as the comparator to all heap functions.
//  std::priority_queue internally uses these algorithms.
// ---------------------------------------------------------------------------

// Helper: print a vector
static void print(const string& label, const vector<int>& v)
{
    cout << label;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

void Heap::demo()
{
    cout << "\n========== Heap Algorithms ==========\n";

    // -----------------------------------------------------------------------
    // std::make_heap  — converts any range into a max-heap in place
    // -----------------------------------------------------------------------
    {
        vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
        print("[make_heap] Before: ", v);
        make_heap(v.begin(), v.end());
        print("[make_heap] After:  ", v);
        cout << "[make_heap] Max element (v[0]): " << v.front() << "\n";
        cout << "[make_heap] Is heap: " << (is_heap(v.begin(), v.end()) ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::push_heap  — insert a new element into the heap
    //   Pattern: push_back the element first, then call push_heap.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {9, 6, 4, 1, 5, 2, 3, 1};  // valid max-heap
        cout << "\n[push_heap] Before: ";
        for (int x : v) cout << x << " ";
        cout << " (max=" << v.front() << ")\n";

        v.push_back(8);                            // add to end
        push_heap(v.begin(), v.end());             // restore heap invariant
        print("[push_heap] After push 8: ", v);
        cout << "[push_heap] New max:     " << v.front() << "\n";
    }

    // -----------------------------------------------------------------------
    // std::pop_heap  — remove the max element from the heap
    //   Pattern: pop_heap moves max to back, then pop_back removes it.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {9, 6, 4, 1, 5, 2, 3, 1};
        make_heap(v.begin(), v.end());
        print("\n[pop_heap] Before: ", v);

        pop_heap(v.begin(), v.end());   // max moved to back
        cout << "[pop_heap] Max (now at back): " << v.back() << "\n";
        v.pop_back();                   // actually remove it
        print("[pop_heap] After pop: ", v);
        cout << "[pop_heap] New max: " << v.front() << "\n";

        // Extract all elements in sorted (descending) order
        vector<int> w = {5, 2, 8, 1, 9, 3};
        make_heap(w.begin(), w.end());
        cout << "\n[pop_heap] Heap-extract all (descending): ";
        while (!w.empty()) {
            pop_heap(w.begin(), w.end());
            cout << w.back() << " ";
            w.pop_back();
        }
        cout << "\n";
    }

    // -----------------------------------------------------------------------
    // std::sort_heap  — sorts a heap into ascending order (destroys heap property)
    //   Equivalent to heap sort.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
        make_heap(v.begin(), v.end());
        print("\n[sort_heap] Max-heap: ", v);
        sort_heap(v.begin(), v.end());  // destroys heap, sorts ascending
        print("[sort_heap] Sorted:   ", v);
        cout << "[sort_heap] Is heap after sort: "
             << (is_heap(v.begin(), v.end()) ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::is_heap / std::is_heap_until
    // -----------------------------------------------------------------------
    {
        vector<int> v = {9, 6, 4, 1, 5, 2, 3};
        cout << "\n[is_heap] {9,6,4,1,5,2,3} is heap: "
             << (is_heap(v.begin(), v.end()) ? "yes" : "no") << "\n";

        // Corrupt the heap
        v[2] = 100;     // v = {9, 6, 100, 1, 5, 2, 3}
        cout << "[is_heap] After v[2]=100: "
             << (is_heap(v.begin(), v.end()) ? "yes" : "no") << "\n";

        auto it = is_heap_until(v.begin(), v.end());
        cout << "[is_heap_until] Heap valid up to index "
             << distance(v.begin(), it) - 1
             << " (breaks at index " << distance(v.begin(), it) << ")\n";
    }

    // -----------------------------------------------------------------------
    // Min-heap — use greater<T> comparator throughout
    // -----------------------------------------------------------------------
    {
        vector<int> v = {5, 2, 8, 1, 9, 3};
        make_heap(v.begin(), v.end(), greater<int>());      // min-heap
        cout << "\n[min-heap] After make_heap(greater): ";
        for (int x : v) cout << x << " ";
        cout << "\n[min-heap] Min element (v[0]): " << v.front() << "\n";

        v.push_back(0);
        push_heap(v.begin(), v.end(), greater<int>());
        cout << "[min-heap] After push 0, min: " << v.front() << "\n";

        pop_heap(v.begin(), v.end(), greater<int>());
        cout << "[min-heap] Pop min: " << v.back() << "\n";
        v.pop_back();
    }
}
