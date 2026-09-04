#include "Stack.h"
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

Stack::Stack() {}

// ---------------------------------------------------------------------------
// std::stack<T>  — container ADAPTOR (LIFO — Last In, First Out)
//   - Wraps an underlying container (default: std::deque) and exposes only
//     LIFO operations. Nothing else is accessible.
//   - Only 5 operations: push / pop / top / size / empty.
//   - NO iterators — you cannot traverse a stack.
//   - Use cases: function call simulation, undo/redo, expression parsing,
//     balanced parentheses checking, DFS traversal.
//
// Template signature:
//   stack<T, Container>
//   default Container = deque<T>
//   can use vector<T> or list<T> as the underlying container instead.
// ---------------------------------------------------------------------------
void Stack::demo()
{
    cout << "\n========== std::stack ==========\n";

    // --- Construction ---
    stack<int> st;   // backed by deque<int> by default

    // You can also use vector as the underlying container:
    // stack<int, vector<int>> st_vec;

    // --- push() — add to the top (O(1)) ---
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << "Pushed: 10, 20, 30, 40\n";

    // --- top() — read the top element without removing it ---
    cout << "top()  : " << st.top()  << " (most recently pushed)\n";
    cout << "size() : " << st.size() << "\n";

    // --- pop() — remove the top element (does NOT return it!) ---
    // Common mistake: st.pop() returns void, not the value.
    // Always read top() BEFORE pop() if you need the value.
    cout << "\nPopping in LIFO order:\n";
    while (!st.empty()) {
        cout << "  top=" << st.top() << "  →  pop\n";
        st.pop();
    }
    cout << "Stack is now empty: " << st.empty() << "\n";

    // --- Practical example: reverse a sequence using a stack ---
    cout << "\n-- Reverse sequence {1,2,3,4,5} using stack --\n";
    stack<int> rev;
    for (int i = 1; i <= 5; ++i) rev.push(i);

    cout << "Reversed: ";
    while (!rev.empty()) {
        cout << rev.top() << " ";
        rev.pop();
    }
    cout << "\n";

    // --- Practical example: check balanced parentheses ---
    cout << "\n-- Balanced parentheses check --\n";
    auto isBalanced = [](const string& expr) -> bool {
        stack<char> s;
        for (char c : expr) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (s.empty()) return false;
                char top = s.top(); s.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) return false;
            }
        }
        return s.empty();
    };

    cout << "\"(a+b)*{c-[d]}\" balanced: " << isBalanced("(a+b)*{c-[d]}") << "\n";
    cout << "\"(a+b*{c}\"       balanced: " << isBalanced("(a+b*{c}")       << "\n";
}
