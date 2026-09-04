#include "Sorting.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

Sorting::Sorting() {}

// ---------------------------------------------------------------------------
// Sorting Algorithms  (<algorithm>)
//
//  std::sort            — O(n log n)  not stable  (introsort: qs + heapsort)
//  std::stable_sort     — O(n log n)  stable      (merge sort, preserves order)
//  std::partial_sort    — sorts only first k elements into place
//  std::nth_element     — guarantees nth position correct, rest unordered O(n)
//
//  "Stable" = equal elements keep their original relative order.
//  Use sort when stability is irrelevant (slightly faster).
//  Use stable_sort when you must preserve relative order of equal elements.
// ---------------------------------------------------------------------------
void Sorting::demo()
{
    cout << "\n========== Sorting Algorithms ==========\n";

    // -----------------------------------------------------------------------
    // std::sort  — fastest general-purpose sort
    //   sort(first, last)               // ascending (default)
    //   sort(first, last, comparator)   // custom ordering
    // -----------------------------------------------------------------------
    {
        vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};
        cout << "[sort] Before: ";
        for (int x : v) cout << x << " ";
        cout << "\n";

        sort(v.begin(), v.end());   // ascending
        cout << "[sort] Ascending:  ";
        for (int x : v) cout << x << " ";
        cout << "\n";

        sort(v.begin(), v.end(), greater<int>());   // descending
        cout << "[sort] Descending: ";
        for (int x : v) cout << x << " ";
        cout << "\n";

        // Custom comparator with a lambda — sort by absolute value
        vector<int> w = {-3, 1, -7, 4, -2};
        sort(w.begin(), w.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        cout << "[sort] By |value|: ";
        for (int x : w) cout << x << " ";
        cout << "\n";
    }

    // -----------------------------------------------------------------------
    // std::stable_sort  — preserves original order of equal elements
    // -----------------------------------------------------------------------
    {
        // Sort words by length, preserving alphabetical order among same-length words
        vector<string> words = {"banana", "apple", "kiwi", "fig", "pear", "mango"};
        cout << "\n[stable_sort] Before: ";
        for (auto& s : words) cout << s << " ";
        cout << "\n";

        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        cout << "[stable_sort] By length (stable): ";
        for (auto& s : words) cout << s << " ";
        cout << "\n";
        // "fig" stays before "pear" because 3 < 4; "apple" before "mango" because 5 == 5, original order kept
    }

    // -----------------------------------------------------------------------
    // std::partial_sort  — places the k smallest elements sorted at [first, k)
    //   Useful when you only need the top-k results.
    //   Complexity: O(n log k)
    // -----------------------------------------------------------------------
    {
        vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};
        int k = 4;
        partial_sort(v.begin(), v.begin() + k, v.end());    // sort first k elements
        cout << "\n[partial_sort] Smallest " << k << " elements in order: ";
        for (int i = 0; i < k; ++i) cout << v[i] << " ";
        cout << "\n";
        cout << "[partial_sort] Remaining (unspecified order): ";
        for (int i = k; i < (int)v.size(); ++i) cout << v[i] << " ";
        cout << "\n";
    }

    // -----------------------------------------------------------------------
    // std::nth_element  — rearranges so v[n] == what it would be if sorted;
    //                     elements before nth are <= nth, elements after are >=.
    //   O(n) average — faster than partial_sort when you don't need them sorted.
    //   Classic use: median / top-k without caring about internal order.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};
        auto mid = v.begin() + v.size() / 2;   // median position
        nth_element(v.begin(), mid, v.end());
        cout << "\n[nth_element] Median of {5,2,8,1,9,3,7,4,6} = " << *mid << "\n";

        // Elements before mid are all <= *mid; after are all >= *mid
        cout << "[nth_element] Left partition  (<= median): ";
        for (auto it = v.begin(); it != mid; ++it) cout << *it << " ";
        cout << "\n";
        cout << "[nth_element] Right partition (>= median): ";
        for (auto it = mid + 1; it != v.end(); ++it) cout << *it << " ";
        cout << "\n";
    }
}
