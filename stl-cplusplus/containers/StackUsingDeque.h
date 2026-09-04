#ifndef STACKUSINGDEQUE_H
#define STACKUSINGDEQUE_H

#include <deque>
#include <cstddef>  // size_t

template <typename T>
class StackUsingDeque
{
public:
    void push(const T& val);
    void pop();
    const T& top() const;
    std::size_t size() const;
    bool empty() const;

private:
    std::deque<T> q_;
};

void demoStackUsingDeque();

#endif // STACKUSINGDEQUE_H
