#include "UnorderedMap.h"
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

UnorderedMap::UnorderedMap() {}

// ---------------------------------------------------------------------------
// std::unordered_map<Key, Value>  — hash table key→value store
//   - Backed by a HASH TABLE (array of linked-list buckets).
//   - Average O(1) insert / find / erase.  Worst case O(n) on hash collision.
//   - Keys are NOT sorted — iteration order is unspecified/arbitrary.
//   - Keys must be hashable (all primitives + std::string work out of the box).
//   - Same API as std::map for insert/find/erase/operator[].
//   - Use over std::map when you don't need sorted order and want faster lookups.
//
// How hashing works:
//   hash(key) % bucket_count → bucket index → linked list of entries there
//
//   key "Alice" → hash → 7 → bucket[7] → [("Alice",95)]
//   key "Bob"   → hash → 3 → bucket[3] → [("Bob",87)]
//   key "Carol" → hash → 7 → bucket[7] → [("Alice",95)] → [("Carol",92)]
//                                          ↑ COLLISION — both land in bucket 7
// ---------------------------------------------------------------------------
void UnorderedMap::demo()
{
    cout << "\n========== std::unordered_map ==========\n";

    // --- Construction ---
    unordered_map<string, int> scores;

    // --- Insertion ---
    scores["Alice"] = 95;       // operator[]: inserts if not present, then assigns
    scores["Bob"]   = 87;
    scores["Carol"] = 92;
    scores.insert({"Dave", 78});     // insert() — does NOT overwrite existing key
    scores.insert({"Alice", 0});     // ignored — Alice already exists

    cout << "Alice's score: " << scores["Alice"] << " (insert duplicate ignored)\n";

    // --- Iteration (order is NOT sorted — arbitrary hash order) ---
    cout << "\nAll scores (no guaranteed order):\n";
    for (const auto& [name, score] : scores)
        cout << "  " << name << " -> " << score << "\n";

    // --- Lookup: find() (O(1) avg) ---
    auto it = scores.find("Bob");
    if (it != scores.end())
        cout << "\nFound Bob: " << it->second << "\n";

    // --- count() — 1 if present, 0 if not ---
    cout << "count(\"Eve\")   : " << scores.count("Eve")   << "\n";
    cout << "count(\"Carol\") : " << scores.count("Carol") << "\n";

    // --- Erase ---
    scores.erase("Dave");
    cout << "\nAfter erase(\"Dave\"), size = " << scores.size() << "\n";

    // --- Hash table internals ---
    cout << "\n-- Hash table internals --\n";
    cout << "bucket_count()     : " << scores.bucket_count()
         << "  (number of hash buckets)\n";
    cout << "load_factor()      : " << scores.load_factor()
         << "  (elements / buckets — lower = fewer collisions)\n";
    cout << "max_load_factor()  : " << scores.max_load_factor()
         << "  (rehash triggered when load exceeds this)\n";

    // Which bucket does "Alice" land in?
    cout << "bucket(\"Alice\")    : " << scores.bucket("Alice") << "\n";

    // --- Rehashing ---
    // When load_factor > max_load_factor, the table rehashes automatically
    // (doubles bucket count, reinserts all elements) — O(n) but amortised O(1).
    scores.rehash(100);   // manually reserve at least 100 buckets
    cout << "After rehash(100), bucket_count = " << scores.bucket_count() << "\n";

    scores.reserve(200);  // reserve space for 200 elements without exceeding max_load_factor
    cout << "After reserve(200), bucket_count = " << scores.bucket_count() << "\n";

    // --- std::map vs std::unordered_map ---
    cout << "\n-- std::map vs std::unordered_map --\n";
    cout << "map           : O(log n) ops, keys sorted, Red-Black Tree\n";
    cout << "unordered_map : O(1) avg ops, no order, Hash Table\n";
    cout << "Choose map when you need sorted iteration or range queries.\n";
    cout << "Choose unordered_map when only lookup/insert/erase matter.\n";

    // --- Practical example: word frequency counter ---
    cout << "\n-- Word frequency counter --\n";
    string sentence = "the cat sat on the mat the cat";
    unordered_map<string, int> freq;
    string word;
    for (char c : sentence) {
        if (c == ' ') {
            if (!word.empty()) { freq[word]++; word.clear(); }
        } else {
            word += c;
        }
    }
    if (!word.empty()) freq[word]++;

    for (const auto& [w, count] : freq)
        cout << "  \"" << w << "\" : " << count << "\n";
}
