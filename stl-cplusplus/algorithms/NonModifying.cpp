#include "NonModifying.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

NonModifying::NonModifying() {}

// ---------------------------------------------------------------------------
// Non-Modifying Sequence Algorithms  (<algorithm>)
// These algorithms READ the range without changing any elements.
//
//  std::for_each       — apply a function to each element (for side-effects)
//  std::count          — count elements equal to value
//  std::count_if       — count elements satisfying predicate
//  std::all_of         — true if ALL elements satisfy predicate (short-circuits)
//  std::any_of         — true if ANY element satisfies predicate (short-circuits)
//  std::none_of        — true if NO element satisfies predicate  (short-circuits)
//  std::min_element    — iterator to smallest element
//  std::max_element    — iterator to largest element
//  std::minmax_element — pair of iterators {min, max} in one pass
//  std::equal          — true if two ranges are element-wise equal
//  std::mismatch       — first position where two ranges differ
// ---------------------------------------------------------------------------
void NonModifying::demo()
{
    cout << "\n========== Non-Modifying Algorithms ==========\n";

    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    cout << "Range: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";

    // -----------------------------------------------------------------------
    // std::for_each  — iterate and apply a callable (does not modify unless
    //                  the callable modifies through a reference)
    // -----------------------------------------------------------------------
    {
        cout << "[for_each] Doubled values: ";
        for_each(v.begin(), v.end(), [](int x) { cout << x * 2 << " "; });
        cout << "\n";
    }

    // -----------------------------------------------------------------------
    // std::count / std::count_if
    // -----------------------------------------------------------------------
    {
        int fives = count(v.begin(), v.end(), 5);
        cout << "[count] Number of 5s: " << fives << "\n";

        int evens = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
        cout << "[count_if] Even elements: " << evens << "\n";

        int big = count_if(v.begin(), v.end(), [](int x) { return x > 4; });
        cout << "[count_if] Elements > 4: " << big << "\n";
    }

    // -----------------------------------------------------------------------
    // std::all_of / std::any_of / std::none_of  — short-circuit evaluation
    // -----------------------------------------------------------------------
    {
        cout << "\n[all_of]  All positive?  " << (all_of(v.begin(),  v.end(), [](int x){ return x > 0; }) ? "yes" : "no") << "\n";
        cout << "[all_of]  All even?      " << (all_of(v.begin(),  v.end(), [](int x){ return x % 2 == 0; }) ? "yes" : "no") << "\n";
        cout << "[any_of]  Any > 8?       " << (any_of(v.begin(),  v.end(), [](int x){ return x > 8; }) ? "yes" : "no") << "\n";
        cout << "[any_of]  Any negative?  " << (any_of(v.begin(),  v.end(), [](int x){ return x < 0; }) ? "yes" : "no") << "\n";
        cout << "[none_of] None negative? " << (none_of(v.begin(), v.end(), [](int x){ return x < 0; }) ? "yes" : "no") << "\n";
        cout << "[none_of] None > 100?   " << (none_of(v.begin(), v.end(), [](int x){ return x > 100; }) ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::min_element / std::max_element / std::minmax_element
    // -----------------------------------------------------------------------
    {
        auto minIt = min_element(v.begin(), v.end());
        auto maxIt = max_element(v.begin(), v.end());
        auto [minIt2, maxIt2] = minmax_element(v.begin(), v.end());   // C++17

        cout << "\n[min_element]    Min = " << *minIt  << " at index " << distance(v.begin(), minIt)  << "\n";
        cout << "[max_element]    Max = " << *maxIt  << " at index " << distance(v.begin(), maxIt)  << "\n";
        cout << "[minmax_element] Min = " << *minIt2 << ", Max = " << *maxIt2 << "  (single pass)\n";

        // Custom comparator: find string with most characters
        vector<string> words = {"apple", "kiwi", "strawberry", "fig", "mango"};
        auto longestIt = max_element(words.begin(), words.end(),
                                     [](const string& a, const string& b){ return a.size() < b.size(); });
        cout << "[max_element]    Longest word: " << *longestIt << "\n";
    }

    // -----------------------------------------------------------------------
    // std::equal  — checks if two ranges contain equal elements
    // -----------------------------------------------------------------------
    {
        vector<int> a = {1, 2, 3, 4, 5};
        vector<int> b = {1, 2, 3, 4, 5};
        vector<int> c = {1, 2, 3, 4, 9};

        cout << "\n[equal] {1,2,3,4,5} == {1,2,3,4,5}: " << (equal(a.begin(), a.end(), b.begin()) ? "yes" : "no") << "\n";
        cout << "[equal] {1,2,3,4,5} == {1,2,3,4,9}: " << (equal(a.begin(), a.end(), c.begin()) ? "yes" : "no") << "\n";

        // Equal with custom comparator (case-insensitive string compare)
        vector<string> s1 = {"Hello", "World"};
        vector<string> s2 = {"hello", "world"};
        bool caseInsensitiveEq = equal(s1.begin(), s1.end(), s2.begin(),
                                       [](const string& x, const string& y) {
                                           if (x.size() != y.size()) return false;
                                           for (size_t i = 0; i < x.size(); ++i)
                                               if (tolower(x[i]) != tolower(y[i])) return false;
                                           return true;
                                       });
        cout << "[equal] \"Hello World\" == \"hello world\" (case-insensitive): "
             << (caseInsensitiveEq ? "yes" : "no") << "\n";
    }

    // -----------------------------------------------------------------------
    // std::mismatch  — finds the first position where two ranges differ.
    //   Returns pair of iterators {it1, it2} pointing to the differing elements.
    // -----------------------------------------------------------------------
    {
        vector<int> a = {1, 2, 3, 7, 5};
        vector<int> b = {1, 2, 3, 4, 5};

        auto [ia, ib] = mismatch(a.begin(), a.end(), b.begin());    // C++17
        if (ia != a.end())
            cout << "\n[mismatch] First difference at index "
                 << distance(a.begin(), ia)
                 << ": a=" << *ia << "  b=" << *ib << "\n";
        else
            cout << "\n[mismatch] Ranges are identical\n";
    }
}
