#include "Map.h"
#include <map>
#include <iostream>

using namespace std;

Map::Map() {}

// ---------------------------------------------------------------------------
// std::map<Key, Value>  — ordered key-value store
//   - Implemented as a self-balancing BST (Red-Black Tree).
//   - Keys are ALWAYS SORTED (ascending by default).
//   - Keys are UNIQUE — inserting a duplicate key overwrites nothing
//     (use operator[] to overwrite, insert() to avoid overwriting).
//   - All operations: O(log n).
//   - Bidirectional iterators; dereferencing gives std::pair<const Key, Value>.
//   - Use when you need sorted keys or range queries.
//   - Use std::unordered_map for O(1) average lookups (no order guarantee).
// ---------------------------------------------------------------------------
void Map::demo()
{
    cout << "\n========== std::map ==========\n";

    // --- Construction ---
    map<string, int> scores;

    // --- Insertion ---
    // operator[] : inserts key with default value (0 for int) if not present,
    //              then assigns. Easy but creates the key even on a failed lookup!
    scores["Alice"] = 95;
    scores["Bob"]   = 87;
    scores["Carol"] = 92;

    // insert()   : does NOT overwrite if key already exists
    scores.insert({"Dave", 78});
    scores.insert({"Alice", 0});   // ignored — Alice already exists
    cout << "Alice's score after duplicate insert: " << scores["Alice"] << "\n";

    // --- Printing: iterating over map gives key-value pairs in SORTED key order ---
    cout << "\nAll scores (sorted by name):\n";
    for (const auto& [name, score] : scores)   // structured binding (C++17)
        cout << "  " << name << " -> " << score << "\n";

    // --- Lookup ---
    // find() — returns iterator to element, or end() if not found
    auto it = scores.find("Bob");
    if (it != scores.end())
        cout << "\nFound Bob: " << it->second << "\n"; // it->first = key, it->second = value

    // count() — returns 1 if key exists, 0 if not (keys are unique in map)
    cout << "count(\"Eve\")   : " << scores.count("Eve")   << " (not present)\n";
    cout << "count(\"Carol\") : " << scores.count("Carol") << " (present)\n";

    // contains() — C++20, cleaner than count()
    // cout << "contains(Bob): " << scores.contains("Bob") << "\n";

    // --- Operator[] for access (WARNING: creates key if missing!) ---
    cout << "scores[\"Carol\"]: " << scores["Carol"] << "\n";
    // scores["Zara"] would INSERT "Zara" with value 0 — be careful!

    // --- Erase ---
    scores.erase("Dave");   // erase by key
    cout << "\nAfter erase(\"Dave\"), size = " << scores.size() << "\n";

    // Erase by iterator
    auto it2 = scores.find("Bob");
    scores.erase(it2);
    cout << "After erase(Bob iterator), size = " << scores.size() << "\n";

    // --- Size / empty ---
    cout << "size()  : " << scores.size()  << "\n";
    cout << "empty() : " << scores.empty() << "\n";

    // --- Iterators ---
    // Bidirectional: ++ and -- but NOT random access
    cout << "\nForward iteration (begin/end):\n";
    for (auto it3 = scores.begin(); it3 != scores.end(); ++it3)
        cout << "  " << it3->first << " -> " << it3->second << "\n";

    cout << "Reverse iteration (rbegin/rend):\n";
    for (auto it3 = scores.rbegin(); it3 != scores.rend(); ++it3)
        cout << "  " << it3->first << " -> " << it3->second << "\n";

    // --- Range queries (possible because keys are sorted) ---
    map<int, string> m = {{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"}};
    auto low = m.lower_bound(2);  // first key >= 2
    auto up  = m.upper_bound(4);  // first key >  4
    cout << "\nKeys in range [2, 4]:\n";
    for (auto it3 = low; it3 != up; ++it3)
        cout << "  " << it3->first << " -> " << it3->second << "\n";
}
