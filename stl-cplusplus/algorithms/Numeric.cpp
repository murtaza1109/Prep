#include "Numeric.h"
#include <numeric>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

Numeric::Numeric() {}

// ---------------------------------------------------------------------------
// Numeric Algorithms  (<numeric>)
//
//  std::iota              — fill range with incrementing values
//  std::accumulate        — fold/reduce left-to-right with initial value
//  std::reduce            — like accumulate but order can vary (C++17, parallelisable)
//  std::inner_product     — dot product / generalised inner product
//  std::partial_sum       — running sum (prefix sums)
//  std::adjacent_difference — difference between consecutive elements
//
//  accumulate vs reduce:
//    - accumulate: order is guaranteed left-to-right, works with non-commutative ops.
//    - reduce:     order is unspecified → use only with associative + commutative ops
//                  in exchange you get parallel execution policy support.
// ---------------------------------------------------------------------------
void Numeric::demo()
{
    cout << "\n========== Numeric Algorithms ==========\n";

    // -----------------------------------------------------------------------
    // std::iota  — fills a range with v, v+1, v+2, … (like Python's range)
    // -----------------------------------------------------------------------
    {
        vector<int> v(8);
        iota(v.begin(), v.end(), 1);    // 1, 2, 3, 4, 5, 6, 7, 8
        cout << "[iota] 1..8: ";
        for (int x : v) cout << x << " ";
        cout << "\n";

        vector<int> w(5);
        iota(w.begin(), w.end(), 10);   // 10, 11, 12, 13, 14
        cout << "[iota] 10..14: ";
        for (int x : w) cout << x << " ";
        cout << "\n";
    }

    // -----------------------------------------------------------------------
    // std::accumulate  — sum / product / custom fold over a range
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5};
        cout << "\n[accumulate] Sum of {1..5}: "
             << accumulate(v.begin(), v.end(), 0)       // 0 is the initial value
             << "\n";

        cout << "[accumulate] Product of {1..5}: "
             << accumulate(v.begin(), v.end(), 1, multiplies<int>())
             << "\n";    // 120

        // String concatenation
        vector<string> words = {"Hello", ", ", "World", "!"};
        string sentence = accumulate(words.begin(), words.end(), string(""));
        cout << "[accumulate] String join: " << sentence << "\n";
    }

    // -----------------------------------------------------------------------
    // std::reduce  — like accumulate but order can vary (C++17)
    //   Use with commutative + associative operations only.
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int sum = reduce(v.begin(), v.end(), 0);    // default op is addition
        cout << "\n[reduce] Sum of {1..10}: " << sum << "\n";

        int product = reduce(v.begin(), v.end(), 1, multiplies<int>());
        cout << "[reduce] Product of {1..10}: " << product << "\n";   // 3628800
    }

    // -----------------------------------------------------------------------
    // std::inner_product  — dot product of two ranges
    //   inner_product(f1, l1, f2, init)
    //   inner_product(f1, l1, f2, init, op_sum, op_mul)  — generalised
    // -----------------------------------------------------------------------
    {
        vector<int> a = {1, 2, 3};
        vector<int> b = {4, 5, 6};
        // dot product: 1*4 + 2*5 + 3*6 = 32
        int dot = inner_product(a.begin(), a.end(), b.begin(), 0);
        cout << "\n[inner_product] Dot product of {1,2,3}·{4,5,6}: " << dot << "\n";

        // Generalised: sum of element-wise max  →  max(1,4)+max(2,5)+max(3,6)
        int sumOfMax = inner_product(a.begin(), a.end(), b.begin(), 0,
                                     plus<int>(),
                                     [](int x, int y){ return max(x, y); });
        cout << "[inner_product] Sum of element-wise max: " << sumOfMax << "\n";   // 4+5+6=15
    }

    // -----------------------------------------------------------------------
    // std::partial_sum  — running totals (prefix sums)
    //   out[i] = in[0] + in[1] + ... + in[i]
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 2, 3, 4, 5};
        vector<int> prefixSums(v.size());
        partial_sum(v.begin(), v.end(), prefixSums.begin());
        cout << "\n[partial_sum] Input:       ";
        for (int x : v) cout << x << " ";
        cout << "\n[partial_sum] Prefix sums: ";
        for (int x : prefixSums) cout << x << " ";
        cout << "\n";   // 1 3 6 10 15

        // Running product
        vector<int> factorials(6);
        iota(v.begin(), v.end(), 1);
        vector<int> input(5);
        iota(input.begin(), input.end(), 1);   // {1,2,3,4,5}
        partial_sum(input.begin(), input.end(), factorials.begin(), multiplies<int>());
        cout << "[partial_sum] Running product (1! to 5!): ";
        for (int i = 0; i < 5; ++i) cout << factorials[i] << " ";
        cout << "\n";   // 1 2 6 24 120
    }

    // -----------------------------------------------------------------------
    // std::adjacent_difference  — difference between consecutive elements
    //   out[0] = in[0]
    //   out[i] = in[i] - in[i-1]   for i > 0
    //   With custom op: generalised (e.g., ratio between consecutive elements)
    // -----------------------------------------------------------------------
    {
        vector<int> v = {1, 3, 6, 10, 15};     // prefix sums from above
        vector<int> diffs(v.size());
        adjacent_difference(v.begin(), v.end(), diffs.begin());
        cout << "\n[adjacent_difference] Input:       ";
        for (int x : v) cout << x << " ";
        cout << "\n[adjacent_difference] Differences: ";
        for (int x : diffs) cout << x << " ";
        cout << "\n";   // 1 2 3 4 5  (the original increments)

        // Custom op — ratio between consecutive elements
        vector<double> prices = {100.0, 110.0, 99.0, 121.0};
        vector<double> ratios(prices.size());
        adjacent_difference(prices.begin(), prices.end(), ratios.begin(),
                            [](double curr, double prev){ return curr / prev; });
        cout << "[adjacent_difference] Price ratios: ";
        cout << ratios[0];   // first element is always copied as-is
        for (size_t i = 1; i < ratios.size(); ++i)
            cout << "  " << ratios[i];
        cout << "\n";
    }
}
