#include "StackUsingDeque.h"
#include <iostream>
#include <string>

using namespace std;

#pragma GCC diagnostic ignored "-Wreturn-type"

template <typename T>
void StackUsingDeque<T>::push(const T& val)
{

}

template <typename T>
void StackUsingDeque<T>::pop()
{

}

template <typename T>
const T& StackUsingDeque<T>::top() const
{

}

template <typename T>
std::size_t StackUsingDeque<T>::size() const
{

}

template <typename T>
bool StackUsingDeque<T>::empty() const
{

}

// ---------------------------------------------------------------------------
// Explicit template instantiation so the linker can find the definitions.
// ---------------------------------------------------------------------------
template class StackUsingDeque<int>;
template class StackUsingDeque<std::string>;


void demoStackUsingDeque()
{
    cout << "\n========== Stack implemented with Deque ==========\n";

    StackUsingDeque<int> s;

    // push a few values
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Pushed: 10, 20, 30\n";

    // top should be the last pushed value
    cout << "top()  : " << s.top()  << "  (expected 30)\n";
    cout << "size() : " << s.size() << "  (expected 3)\n";

    // pop and verify LIFO order
    cout << "\nPopping in LIFO order:\n";
    while (!s.empty()) {
        cout << "  top=" << s.top() << "  →  pop\n";
        s.pop();
    }
    cout << "empty(): " << s.empty() << "  (expected 1)\n";
}
