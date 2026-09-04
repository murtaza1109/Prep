#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

// std::priority_queue — container adaptor implementing a heap
// Default: MAX-heap (largest element is always at the top).
// DOES NOT support iteration — only top/push/pop.
// Header: <queue>

class PriorityQueue
{
public:
    PriorityQueue();
    static void demo();
};

#endif // PRIORITYQUEUE_H
