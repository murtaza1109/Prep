#include "SetOps.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

SetOps::SetOps() {}

// ---------------------------------------------------------------------------
// Set / Merge Algorithms  (<algorithm>)
// ALL of these require SORTED input ranges.
//
//  std::merge                 — merge two sorted ranges into a third      O(n+m)
//  std::inplace_merge         — merge two sorted sub-ranges in place      O(n log n)
//  std::includes              — true if one sorted range contains another O(n+m)
//  std::set_union             — elements in A OR B (duplicates kept once) O(n+m)
//  std::set_intersection      — elements in A AND B                       O(n+m)
//  std::set_difference        — elements in A but NOT in B                O(n+m)
//  std::set_symmetric_difference — elements in A XOR B (not in both)     O(n+m)
//
//  These match mathematical set operations, but they work on SORTED multisets
//  (duplicates are handled correctly by multiplicity, not just membership).
// ---------------------------------------------------------------------------

// Helper: print a vector
static void print(const string& label, const vector<int>& v)
{
    cout << label;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

void SetOps::demo()
{
    cout << "\n========== Set / Merge Algorithms ==========\n";

    vector<int> A = {1, 2, 4, 6, 8};
    vector<int> B = {2, 3, 4, 5, 6, 9};

    cout << "A = "; for (int x : A) cout << x << " "; cout << "\n";
    cout << "B = "; for (int x : B) cout << x << " "; cout << "\n\n";

    // -----------------------------------------------------------------------
    // std::merge  — merges two sorted ranges into a new sorted range
    // -----------------------------------------------------------------------
    {
        vector<int> merged(A.size() + B.size());
        merge(A.begin(), A.end(), B.begin(), B.end(), merged.begin());
        print("[merge]               A ∪ B (with dups): ", merged);
    }

    // -----------------------------------------------------------------------
    // std::inplace_merge  — merges two ADJACENT sorted sub-ranges in place
    //   Commonly used after inserting elements into a sorted vector.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 3, 5, 7,   2, 4, 6, 8};    // two sorted halves
        auto mid = v.begin() + 4;
        print("[inplace_merge]       Before: ", v);
        inplace_merge(v.begin(), mid, v.end());
        print("[inplace_merge]       After:  ", v);
    }

    // -----------------------------------------------------------------------
    // std::includes  — tests if every element of B is present in A
    // -----------------------------------------------------------------------
    {
        vector<int> super_set = {1, 2, 3, 4, 5, 6};
        vector<int> sub_set   = {2, 4, 6};
        vector<int> not_sub   = {2, 4, 7};

        cout << "\n[includes] {1..6} contains {2,4,6}:  "
             << (includes(super_set.begin(), super_set.end(), sub_set.begin(), sub_set.end()) ? "yes" : "no") << "\n";
        cout << "[includes] {1..6} contains {2,4,7}:  "
             << (includes(super_set.begin(), super_set.end(), not_sub.begin(), not_sub.end()) ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::set_union  — elements in A OR B; if element appears k times in A
    //                   and m times in B, output has max(k,m) copies.
    // -----------------------------------------------------------------------
    {
        vector<int> result;
        set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
        print("\n[set_union]           A | B: ", result);
    }

    // -----------------------------------------------------------------------
    // std::set_intersection  — elements in A AND B; min(k,m) copies
    // -----------------------------------------------------------------------
    {
        vector<int> result;
        set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
        print("[set_intersection]    A & B: ", result);
    }

    // -----------------------------------------------------------------------
    // std::set_difference  — elements in A but NOT in B; max(k-m, 0) copies
    // -----------------------------------------------------------------------
    {
        vector<int> result;
        set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
        print("[set_difference]      A - B: ", result);

        vector<int> result2;
        set_difference(B.begin(), B.end(), A.begin(), A.end(), back_inserter(result2));
        print("[set_difference]      B - A: ", result2);
    }

    // -----------------------------------------------------------------------
    // std::set_symmetric_difference  — elements in A XOR B (in A or B, not both)
    // -----------------------------------------------------------------------
    {
        vector<int> result;
        set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
        print("[set_symmetric_diff]  A Δ B: ", result);
    }
}
