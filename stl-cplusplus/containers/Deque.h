#ifndef DEQUE_H
#define DEQUE_H

// std::deque — double-ended queue
// Fast insert/remove at BOTH front AND back (O(1)).
// Slower random access compared to vector; not contiguous in memory.
// Header: <deque>

class Deque
{
public:
    Deque();
    static void demo();
};

#endif // DEQUE_H
