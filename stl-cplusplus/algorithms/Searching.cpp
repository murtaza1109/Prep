#include "Searching.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Searching::Searching() {}

// ---------------------------------------------------------------------------
// Searching Algorithms  (<algorithm>)
//
//  std::find          — linear search by value            O(n)
//  std::find_if       — linear search by predicate        O(n)
//  std::find_if_not   — linear search, first non-match    O(n)
//  std::binary_search — yes/no existence check (sorted)  O(log n)
//  std::lower_bound   — first position >= value (sorted)  O(log n)
//  std::upper_bound   — first position >  value (sorted)  O(log n)
//  std::equal_range   — [lower_bound, upper_bound) pair   O(log n)
//
//  IMPORTANT: binary_search / lower_bound / upper_bound / equal_range
//             REQUIRE the range to be sorted (or partitioned by comparator).
// ---------------------------------------------------------------------------
void Searching::demo()
{
    cout << "\n========== Searching Algorithms ==========\n";

    // -----------------------------------------------------------------------
    // std::find  — returns iterator to first matching element, or end()
    // -----------------------------------------------------------------------
    {
        vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
        auto it = find(v.begin(), v.end(), 5);
        if (it != v.end())
            cout << "[find] Found 5 at index " << distance(v.begin(), it) << "\n";
        else
            cout << "[find] 5 not found\n";

        auto it2 = find(v.begin(), v.end(), 42);
        cout << "[find] 42 found: " << (it2 != v.end() ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::find_if  — searches for first element satisfying a predicate
    // std::find_if_not — first element NOT satisfying the predicate
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 3, 7, 8, 10, 13};

        // find first even number
        auto it = find_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
        if (it != v.end())
            cout << "[find_if] First even: " << *it << "\n";

        // find first odd number
        auto it2 = find_if_not(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
        if (it2 != v.end())
            cout << "[find_if_not] First non-odd (i.e. even): " << *it2 << "\n";

        // find first element > 9
        auto it3 = find_if(v.begin(), v.end(), [](int x) { return x > 9; });
        if (it3 != v.end())
            cout << "[find_if] First element > 9: " << *it3 << "\n";
    }

    // -----------------------------------------------------------------------
    // std::binary_search  — O(log n), only works on SORTED ranges
    //   Returns bool — tells you IF value exists, not WHERE.
    //   Use lower_bound / equal_range if you also need position.
    // -----------------------------------------------------------------------
    {
        vector<int> sorted = {1, 2, 4, 4, 5, 7, 9, 11};
        cout << "\n[binary_search] Range: 1 2 4 4 5 7 9 11\n";
        cout << "[binary_search] Contains 4:  " << (binary_search(sorted.begin(), sorted.end(), 4)  ? "yes" : "no") << "\n";
        cout << "[binary_search] Contains 6:  " << (binary_search(sorted.begin(), sorted.end(), 6)  ? "yes" : "no") << "\n";
        cout << "[binary_search] Contains 11: " << (binary_search(sorted.begin(), sorted.end(), 11) ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::lower_bound — iterator to first element >= value
    // std::upper_bound — iterator to first element >  value
    //
    //  Together they define the half-open range [lower, upper) of elements
    //  equal to the target value.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 4, 4, 5, 7, 9, 11};
        cout << "\n[lower/upper_bound] Range: 1 2 4 4 5 7 9 11\n";

        auto lo = lower_bound(v.begin(), v.end(), 4);   // first >= 4  → index 2
        auto hi = upper_bound(v.begin(), v.end(), 4);   // first >  4  → index 4

        cout << "[lower_bound] First index with value >= 4: " << distance(v.begin(), lo) << "  (value=" << *lo << ")\n";
        cout << "[upper_bound] First index with value >  4: " << distance(v.begin(), hi) << "  (value=" << *hi << ")\n";
        cout << "[derived]     Count of 4s in range: " << distance(lo, hi) << "\n";

        // Insertion point — where to insert 6 to keep sorted order
        auto pos = lower_bound(v.begin(), v.end(), 6);
        cout << "[lower_bound] Insert 6 before index: " << distance(v.begin(), pos) << "\n";
    }

    // -----------------------------------------------------------------------
    // std::equal_range — returns {lower_bound, upper_bound} as a pair in one call
    //   Useful when you need both bounds (avoids two separate binary searches).
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 4, 4, 4, 7, 9};
        cout << "\n[equal_range] Range: 1 2 4 4 4 7 9\n";

        auto [lo, hi] = equal_range(v.begin(), v.end(), 4);    // C++17 structured binding
        cout << "[equal_range] 4 appears at indices ["
             << distance(v.begin(), lo) << ", "
             << distance(v.begin(), hi) << ")  — count: "
             << distance(lo, hi) << "\n";

        // Searching in a sorted vector of strings
        vector<string> names = {"Alice", "Bob", "Charlie", "Charlie", "Dave"};
        auto [lo2, hi2] = equal_range(names.begin(), names.end(), string("Charlie"));
        cout << "[equal_range] 'Charlie' appears " << distance(lo2, hi2) << " time(s)\n";
    }
}
