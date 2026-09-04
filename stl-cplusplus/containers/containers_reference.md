# C++ STL Containers Reference

## Sequential Containers

| Container | Use when |
|---|---|
| `array` | Size is known at compile time and never changes. Zero overhead, stack-allocated. E.g. days of week, RGB channels, fixed-size buffers. |
| `vector` | Default choice for any dynamic list. You mostly append to the end and need fast random access. |
| `deque` | You need fast insertion/removal at **both** front and back. E.g. sliding window, undo history, job queue where items are also cancelled from front. |
| `list` | You frequently insert or remove **in the middle** and you already hold an iterator there. E.g. LRU cache eviction, real-time task rescheduling. |
| `string` | Storing and manipulating text. Need `find`, `substr`, `replace`, or interop with C APIs via `c_str()`. |

---

## Adaptor Containers

| Container | Use when |
|---|---|
| `stack` | You need strict LIFO discipline. E.g. undo/redo, recursive algorithm simulation, expression parsing, DFS. |
| `queue` | You need strict FIFO discipline. E.g. BFS, print spooler, request processing, producer-consumer buffer. |
| `priority_queue` | You always need the highest (or lowest) priority item next, not just the oldest. E.g. Dijkstra's shortest path, task scheduling by urgency, event simulation. |

---

## Associative Containers

| Container | Use when |
|---|---|
| `map` | You need key→value lookup **and** keys must stay sorted. E.g. a dictionary, leaderboard where you need top-N range, event log by timestamp. |
| `multimap` | Same as `map` but multiple entries can share the same key. E.g. grouping students by grade. |
| `unordered_map` | You need key→value lookup and don't care about order. Fastest option for pure lookup/insert/erase. E.g. word frequency counter, caching, index tables. |
| `set` | You need a collection of **unique** values that stays sorted. E.g. tracking visited nodes in a graph, maintaining a sorted whitelist with range queries. |
| `multiset` | Same as `set` but duplicates are allowed. E.g. counting occurrences while keeping sorted order. |
| `unordered_set` | You need fast membership testing and don't care about order. E.g. checking if an item was already seen, deduplication of a large list. |

---

## Complexity Comparison — Sequential & Adaptors

| Container | Random Access | Front insert/remove | Back insert/remove | Middle insert/erase | Search | Iterators | Memory |
|---|---|---|---|---|---|---|---|
| `array` | O(1) | O(n) | O(n) | O(n) | O(n) | Random-access | Stack, contiguous |
| `vector` | O(1) | O(n) | O(1) amortised | O(n) | O(n) | Random-access | Heap, contiguous |
| `deque` | O(1) | O(1) | O(1) | O(n) | O(n) | Random-access | Heap, chunked |
| `list` | — | O(1) | O(1) | O(1) ✱ | O(n) | Bidirectional | Heap, per-node |
| `string` | O(1) | O(n) | O(1) amortised | O(n) | O(n) `find()` | Random-access | SSO / Heap |
| `stack` | top only | — | O(1) push/pop | — | — | None | Via deque |
| `queue` | front/back only | O(1) pop | O(1) push | — | — | None | Via deque |
| `priority_queue` | top only (max/min) | — | O(log n) push/pop | — | — | None | Via vector |

✱ O(1) only once you already hold an iterator to the position — getting to it is O(n).

---

## Complexity Comparison — Associative Containers

| Container | Key Lookup | Insert | Erase | Duplicates | Iteration Order | Iterators | Memory |
|---|---|---|---|---|---|---|---|
| `map` | O(log n) | O(log n) | O(log n) | No | Sorted by key | Bidirectional | Heap, tree nodes |
| `multimap` | O(log n) | O(log n) | O(log n) | Yes | Sorted by key | Bidirectional | Heap, tree nodes |
| `unordered_map` | O(1) avg | O(1) avg | O(1) avg | No | None | Forward | Heap, hash buckets |
| `set` | O(log n) | O(log n) | O(log n) | No | Sorted | Bidirectional | Heap, tree nodes |
| `multiset` | O(log n) | O(log n) | O(log n) | Yes | Sorted | Bidirectional | Heap, tree nodes |
| `unordered_set` | O(1) avg | O(1) avg | O(1) avg | No | None | Forward | Heap, hash buckets |

> **Sorted order** (`map`, `set`) costs O(log n) per operation but enables range queries (`lower_bound` / `upper_bound`).  
> **Hash-based** (`unordered_map`, `unordered_set`) gives O(1) avg but no ordering and occasional O(n) worst case on collision.

---

## Iterator Categories

| Category | Supports | Containers |
|---|---|---|
| Random-access | `++`, `--`, `+n`, `-n`, `[]`, `<`, `>` | `vector`, `deque`, `array`, `string` |
| Bidirectional | `++`, `--` | `list`, `map`, `set` |
| Forward | `++` only | `unordered_map`, `unordered_set` |
| None | — | `stack`, `queue`, `priority_queue` |

More capable iterators can be used wherever a less capable one is required.  
`std::sort` requires random-access — that is why it does not work on `list`.

---

## Quick Decision Rule

```
Need key→value?
  └─ yes → need sorted / range queries? → map        : unordered_map
  └─ no  → need uniqueness only?
              └─ yes → need sorted?     → set        : unordered_set
              └─ no  → need both-end insert?  → deque
                        need middle insert?    → list
                        need priority order?   → priority_queue
                        need LIFO?             → stack
                        need FIFO?             → queue
                        otherwise              → vector   ← default
```
