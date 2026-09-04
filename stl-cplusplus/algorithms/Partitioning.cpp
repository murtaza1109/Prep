#include "Partitioning.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Partitioning::Partitioning() {}

// ---------------------------------------------------------------------------
// Partitioning Algorithms  (<algorithm>)
//
//  A range is PARTITIONED with respect to a predicate P when all elements for
//  which P is true come before all elements for which P is false.
//  (This is exactly the pre-condition that binary_search etc. rely on.)
//
//  std::is_partitioned  — check if range is already partitioned      O(n)
//  std::partition       — rearrange into [true-group | false-group]   O(n)
//  std::stable_partition— same but preserves relative order           O(n log n)
//  std::partition_point — binary search for the boundary iterator
//                         (like lower_bound but for a predicate)      O(log n)
//  std::partition_copy  — copy elements into two separate destinations O(n)
// ---------------------------------------------------------------------------
void Partitioning::demo()
{
    cout << "\n========== Partitioning Algorithms ==========\n";

    // -----------------------------------------------------------------------
    // std::is_partitioned
    // -----------------------------------------------------------------------
    {
        vector<int> v1 = {2, 4, 6, 1, 3, 5};   // evens then odds → partitioned
        vector<int> v2 = {1, 2, 3, 4, 5, 6};   // not partitioned by "even" predicate

        auto isEven = [](int x) { return x % 2 == 0; };

        cout << "[is_partitioned] {2,4,6,1,3,5} by even: "
             << (is_partitioned(v1.begin(), v1.end(), isEven) ? "yes" : "no") << "\n";
        cout << "[is_partitioned] {1,2,3,4,5,6} by even: "
             << (is_partitioned(v2.begin(), v2.end(), isEven) ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::partition  — rearranges, does NOT preserve relative order
    //   Returns iterator to the start of the false-group (the partition point).
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
        cout << "\n[partition]   Before: ";
        for (int x : v) cout << x << " ";
        cout << "\n";

        auto pPoint = partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

        cout << "[partition]   After (evens | odds): ";
        for (int x : v) cout << x << " ";
        cout << "\n";
        cout << "[partition]   Partition boundary index: "
             << distance(v.begin(), pPoint) << "\n";
    }

    // -----------------------------------------------------------------------
    // std::stable_partition  — preserves relative order within each group
    //   Slightly more expensive (O(n log n)) but deterministic output.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
        cout << "\n[stable_partition]   Before: ";
        for (int x : v) cout << x << " ";
        cout << "\n";

        auto pPoint = stable_partition(v.begin(), v.end(),
                                       [](int x){ return x % 2 == 0; });

        cout << "[stable_partition]   After (evens | odds): ";
        for (int x : v) cout << x << " ";
        cout << "\n";
        // Output: 2 4 6 8 | 1 3 5 7  (original relative order preserved)
        cout << "[stable_partition]   Partition boundary index: "
             << distance(v.begin(), pPoint) << "\n";
    }

    // -----------------------------------------------------------------------
    // std::partition_point  — binary search on a partitioned range.
    //   Finds the iterator to the first element for which the predicate is FALSE.
    //   Requires the range to already be partitioned! O(log n).
    // -----------------------------------------------------------------------
    {
        // Already partitioned: evens first, odds after
        vector<int> v = {2, 4, 6, 8, 1, 3, 5, 7};
        auto pp = partition_point(v.begin(), v.end(),
                                  [](int x){ return x % 2 == 0; });
        cout << "\n[partition_point] Boundary index (first odd): "
             << distance(v.begin(), pp)
             << "  (value=" << *pp << ")\n";
    }

    // -----------------------------------------------------------------------
    // std::partition_copy  — splits range into two separate output containers
    //   Elements satisfying predicate → out_true
    //   Elements not satisfying       → out_false
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> evens, odds;
        partition_copy(v.begin(), v.end(),
                       back_inserter(evens),
                       back_inserter(odds),
                       [](int x){ return x % 2 == 0; });

        cout << "\n[partition_copy] Evens: ";
        for (int x : evens) cout << x << " ";
        cout << "\n";
        cout << "[partition_copy] Odds:  ";
        for (int x : odds) cout << x << " ";
        cout << "\n";
    }
}
