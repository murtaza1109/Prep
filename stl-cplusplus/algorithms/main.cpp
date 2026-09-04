#include <iostream>

// STL Algorithm demo headers
#include "Sorting.h"
#include "Searching.h"
#include "NonModifying.h"
#include "Modifying.h"
#include "Numeric.h"
#include "Partitioning.h"
#include "SetOps.h"
#include "Heap.h"

// =============================================================================
// STL Algorithm Demo — Overview for new C++ developers
// =============================================================================
//
// The Standard Template Library (STL) ships with ~100 generic algorithms in
// <algorithm> and <numeric>. They work on ANY range expressed as a pair of
// iterators, so the same algorithm works on vector, deque, array, list, etc.
//
// ALGORITHM CATEGORIES
// ─────────────────────────────────────────────────────────────────────────────
// Non-modifying     — inspect / query a range without changing it
//   for_each, count, count_if, all_of, any_of, none_of,
//   find, find_if, min_element, max_element, equal, mismatch
//
// Sorting           — reorder elements
//   sort, stable_sort, partial_sort, nth_element
//
// Partitioning      — split range into two groups by a predicate
//   partition, stable_partition, is_partitioned,
//   partition_point, partition_copy
//
// Searching         — locate elements / test existence
//   find, find_if, binary_search, lower_bound, upper_bound, equal_range
//   (binary_* require a sorted / partitioned range)
//
// Modifying         — write to or rearrange elements in place
//   copy, copy_if, transform, fill, replace, remove, unique,
//   reverse, rotate, shuffle
//
// Set algorithms    — mathematical set ops on sorted ranges
//   merge, inplace_merge, includes,
//   set_union, set_intersection, set_difference, set_symmetric_difference
//
// Heap algorithms   — binary max-heap operations on a flat array
//   make_heap, push_heap, pop_heap, sort_heap, is_heap
//
// Numeric           — arithmetic algorithms  (<numeric>)
//   iota, accumulate, reduce, inner_product, partial_sum, adjacent_difference
//
// KEY CONCEPTS
// ─────────────────────────────────────────────────────────────────────────────
// Iterator ranges   — [first, last) half-open, last is one past the end.
// Predicates        — callable returning bool; prefer lambdas over functors.
// Comparators       — binary callable: comp(a,b) returns true if a < b.
// back_inserter     — output iterator that calls push_back(); grows containers.
// Erase-remove idiom— remove() + container.erase(newEnd, end()) to shrink.
// =============================================================================

int main()
{
    std::cout << "╔══════════════════════════════════════════════╗\n";
    std::cout << "║         C++ STL Algorithms Demo              ║\n";
    std::cout << "╚══════════════════════════════════════════════╝\n";

    Sorting::demo();        // sort, stable_sort, partial_sort, nth_element
    Searching::demo();      // find, find_if, binary_search, lower/upper_bound, equal_range
    NonModifying::demo();   // for_each, count, all_of/any_of/none_of, min/max_element, equal
    Modifying::demo();      // copy, transform, fill, replace, remove, unique, reverse, rotate, shuffle
    Numeric::demo();        // iota, accumulate, reduce, inner_product, partial_sum, adjacent_difference
    Partitioning::demo();   // partition, stable_partition, is_partitioned, partition_point
    SetOps::demo();         // merge, set_union, set_intersection, set_difference, set_symmetric_difference
    Heap::demo();           // make_heap, push_heap, pop_heap, sort_heap, is_heap

    std::cout << "\n========== Done ==========\n";
    return 0;
}
