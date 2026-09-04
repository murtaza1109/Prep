#include "Modifying.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <random>

using namespace std;

Modifying::Modifying() {}

// ---------------------------------------------------------------------------
// Modifying Sequence Algorithms  (<algorithm>)
// These algorithms write to the destination range or rearrange elements.
//
//  std::copy / copy_if    — copy elements to another range
//  std::transform         — apply a function and write results to output
//  std::fill / fill_n     — assign a value to every element
//  std::replace/replace_if— replace matched elements with a new value
//  std::remove/remove_if  — "erase-remove" idiom (does not shrink container)
//  std::unique            — remove consecutive duplicates
//  std::reverse           — reverse a range in place
//  std::rotate            — bring middle to front
//  std::shuffle           — randomly permute elements
// ---------------------------------------------------------------------------

// Helper: print a vector
static void print(const string& label, const vector<int>& v)
{
    cout << label;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

void Modifying::demo()
{
    cout << "\n========== Modifying Algorithms ==========\n";

    // -----------------------------------------------------------------------
    // std::copy  — copies [first, last) into output starting at dest
    // std::copy_if — copies only elements satisfying a predicate
    // -----------------------------------------------------------------------
    {
        vector<int> src = {1, 2, 3, 4, 5, 6, 7, 8};
        vector<int> dst(src.size());

        copy(src.begin(), src.end(), dst.begin());
        print("[copy]    Destination: ", dst);

        vector<int> evens;
        copy_if(src.begin(), src.end(), back_inserter(evens),
                [](int x) { return x % 2 == 0; });  // back_inserter grows evens as needed
        print("[copy_if] Even elements: ", evens);
    }

    // -----------------------------------------------------------------------
    // std::transform  — applies a unary (or binary) function, writes results
    //   Unary form:  transform(first, last, dest, unary_op)
    //   Binary form: transform(first1, last1, first2, dest, binary_op)
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5};
        vector<int> squared(v.size());

        transform(v.begin(), v.end(), squared.begin(),
                  [](int x) { return x * x; });
        print("[transform] Squares: ", squared);

        // Binary transform — add two vectors element-wise
        vector<int> a = {1, 2, 3};
        vector<int> b = {10, 20, 30};
        vector<int> sums(3);
        transform(a.begin(), a.end(), b.begin(), sums.begin(),
                  [](int x, int y) { return x + y; });
        print("[transform] Element-wise sums: ", sums);
    }

    // -----------------------------------------------------------------------
    // std::fill / std::fill_n
    // -----------------------------------------------------------------------
    {
        vector<int> v(6);
        fill(v.begin(), v.end(), 7);
        print("\n[fill]   All 7s: ", v);

        fill_n(v.begin(), 3, 0);    // fill only first 3 elements
        print("[fill_n] First 3 zeroed: ", v);
    }

    // -----------------------------------------------------------------------
    // std::replace / std::replace_if
    //   Replace elements in place — O(n).
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        print("\n[replace]    Before: ", v);
        replace(v.begin(), v.end(), 2, 99);     // replace all 2s with 99
        print("[replace]    After (2→99): ", v);

        vector<int> w = {1, 2, 3, 4, 5, 6};
        replace_if(w.begin(), w.end(),
                   [](int x) { return x % 2 == 0; },    // predicate: even
                   0);                                   // replace with 0
        print("[replace_if] Evens → 0: ", w);
    }

    // -----------------------------------------------------------------------
    // std::remove / std::remove_if  — ERASE-REMOVE IDIOM
    //   remove() moves unwanted elements to the back and returns an iterator
    //   to the new logical end. It does NOT shrink the container.
    //   You must call erase() yourself to actually remove the trailing elements.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        print("\n[remove]    Before: ", v);

        // Step 1: remove logically — shifts elements, returns new end
        auto newEnd = remove(v.begin(), v.end(), 2);
        // Step 2: erase the now-meaningless tail
        v.erase(newEnd, v.end());
        print("[remove]    After erase-remove of 2s: ", v);

        vector<int> w = {1, 2, 3, 4, 5, 6, 7, 8};
        auto newEnd2 = remove_if(w.begin(), w.end(),
                                 [](int x) { return x % 2 == 0; });
        w.erase(newEnd2, w.end());
        print("[remove_if] After erase-remove of evens: ", w);
    }

    // -----------------------------------------------------------------------
    // std::unique  — removes CONSECUTIVE duplicates (combine with sort first
    //               to remove ALL duplicates from the container)
    // -----------------------------------------------------------------------
    {
        vector<int> v = {3, 1, 1, 2, 3, 3, 4, 4, 5};
        print("\n[unique]   Before (unsorted): ", v);

        // Remove consecutive duplicates only
        auto newEnd = unique(v.begin(), v.end());
        v.erase(newEnd, v.end());
        print("[unique]   After (consecutive dups removed): ", v);

        // Sort first, then unique → removes ALL duplicates
        vector<int> w = {5, 3, 1, 4, 1, 5, 9, 2, 6, 5};
        sort(w.begin(), w.end());
        auto newEnd2 = unique(w.begin(), w.end());
        w.erase(newEnd2, w.end());
        print("[unique]   All duplicates removed (sort+unique): ", w);
    }

    // -----------------------------------------------------------------------
    // std::reverse  — reverses elements in place
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5};
        print("\n[reverse]  Before: ", v);
        reverse(v.begin(), v.end());
        print("[reverse]  After:  ", v);

        string s = "racecar";
        cout << "[reverse]  String before: " << s << "\n";
        reverse(s.begin(), s.end());
        cout << "[reverse]  String after:  " << s << "\n";
    }

    // -----------------------------------------------------------------------
    // std::rotate  — brings the element at `middle` to the front
    //   rotate(first, middle, last)
    //   Result: [middle, last) followed by [first, middle)
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5, 6};
        print("\n[rotate]  Before: ", v);
        rotate(v.begin(), v.begin() + 2, v.end());   // bring index 2 to front
        print("[rotate]  After rotate(begin+2): ", v);
    }

    // -----------------------------------------------------------------------
    // std::shuffle  — randomly permutes the range using a Mersenne Twister RNG
    //   (Replaces the old std::random_shuffle which is removed in C++17.)
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7};
        print("\n[shuffle] Before: ", v);
        mt19937 rng(42);    // seeded Mersenne Twister
        shuffle(v.begin(), v.end(), rng);
        print("[shuffle] After:  ", v);
    }
}
