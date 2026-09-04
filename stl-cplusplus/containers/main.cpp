#include <iostream>

// STL Container demo headers
#include "Array.h"
#include "Vector.h"
#include "Deque.h"
#include "PriorityQueue.h"
#include "List.h"
#include "Map.h"
#include "Set.h"
#include "Stack.h"
#include "Queue.h"
#include "StackUsingDeque.h"
#include "StringDemo.h"
#include "UnorderedMap.h"

// =============================================================================
// STL Container Demo — Overview for new C++ developers
// =============================================================================
//
// The Standard Template Library (STL) provides ready-made containers, iterators,
// and algorithms that are generic (work with any type via templates).
//
// CONTAINER CATEGORIES
// ─────────────────────────────────────────────────────────────────────────────
// Sequential containers — elements in a specific order you control:
//   array          Fixed size, stack-allocated, no overhead.
//   vector         Dynamic array; fast random access + fast append.
//   deque          Dynamic, fast insert/remove at BOTH ends.
//   list           Doubly linked list; O(1) insert/erase anywhere.
//
// Associative containers — automatically ordered by key/value:
//   set            Sorted, unique elements.         (Red-Black Tree)
//   map            Sorted key→value pairs.          (Red-Black Tree)
//   multiset       Sorted, duplicates allowed.
//   multimap       Sorted key→value, dup keys ok.
//
// Unordered (hash-based) containers — average O(1) lookup, no order:
//   unordered_set / unordered_map / unordered_multiset / unordered_multimap
//
// Container adaptors — restrict interface of an underlying container:
//   stack          LIFO — push/pop/top   (default: deque)      ← covered
//   queue          FIFO — push/pop/front (default: deque)      ← covered
//   priority_queue Max/min-heap          (default: vector + heap) ← covered
//
// Special containers:
//   string         Dynamic char array with text operations + SSO ← covered
//   unordered_map  Hash table key→value, O(1) avg               ← covered
//
// ITERATOR CATEGORIES (from most to least capable)
// ─────────────────────────────────────────────────────────────────────────────
//   Random-Access   ++, --, +n, -n, [], <, >    vector, deque, array
//   Bidirectional   ++, --                       list, map, set
//   Forward         ++  only                     forward_list, unordered_*
//   Input/Output    single-pass read/write        stream iterators
//
// More capable iterators can be used wherever a less capable one is required.
// STL algorithms declare which category they need (e.g. sort needs random-access).
// =============================================================================

int main()
{
    std::cout << "╔══════════════════════════════════════════════╗\n";
    std::cout << "║         C++ STL Containers Demo              ║\n";
    std::cout << "╚══════════════════════════════════════════════╝\n";

    Array::demo();          // std::array          — fixed-size, stack array
    Vector::demo();         // std::vector         — dynamic array
    Deque::demo();          // std::deque          — double-ended queue
    PriorityQueue::demo();  // std::priority_queue — max/min heap
    List::demo();           // std::list           — doubly linked list
    Map::demo();            // std::map            — sorted key→value store
    Set::demo();            // std::set            — sorted unique values
    Stack::demo();          // std::stack          — LIFO adaptor
    Queue::demo();          // std::queue          — FIFO adaptor
    demoStackUsingDeque();  // Stack built on Deque — adapter pattern live demo
    StringDemo::demo();     // std::string         — dynamic text container
    UnorderedMap::demo();   // std::unordered_map  — hash table key→value store

    std::cout << "\n========== Done ==========\n";
    return 0;
}

