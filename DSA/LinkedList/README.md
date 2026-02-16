# LinkedList with Google Test

A comprehensive C++ implementation of LinkedList data structure with unit tests using Google Test framework.

## Features

- **LinkedList Operations:**
  - Push back elements
  - Reverse (iterative and recursive)
  - Loop detection and analysis
  - Add two numbers represented as linked lists
  - Y-bridge detection (merge point of two lists)
  - Remove nth node from back

## Project Structure

```
LinkedList/
├── List.h              # Header file with declarations
├── List.cpp            # Implementation file
├── list_test.cpp       # Google Test unit tests (31 tests)
├── main.cpp            # Demo file (optional)
├── LinkedList.pro      # Qt project file
└── README.md           # This file
```

## Prerequisites

- C++17 or later
- Google Test framework
- macOS with Homebrew (or adjust paths for your system)

## Installation

### Install Google Test (macOS):
```bash
brew install googletest
```

### For other systems:
- Ubuntu/Debian: `sudo apt-get install libgtest-dev`
- Windows: Follow [Google Test installation guide](https://github.com/google/googletest)

## Building and Running Tests

### Option 1: Direct compilation with g++
```bash
cd /path/to/LinkedList
g++ -std=c++17 -I/opt/homebrew/include list_test.cpp List.cpp \
    -L/opt/homebrew/lib -lgtest -lgtest_main -pthread -o list_tests
./list_tests
```

### Option 2: Using Qt Creator
1. Open `LinkedList.pro` in Qt Creator
2. Build the project (Cmd+B / Ctrl+B)
3. Run the tests (Cmd+R / Ctrl+R)

### Option 3: Using qmake
```bash
qmake
make
./LinkedList
```

## Test Coverage

The test suite includes **31 comprehensive tests** covering:

### Basic Operations (3 tests)
- Empty list creation
- Push back single/multiple elements

### Reverse Operations (7 tests)
- Iterative reverse (empty, single, multiple elements)
- Recursive reverse (empty, single, multiple elements)
- Static reverse method

### Loop Detection (6 tests)
- Detect loops in empty/normal/looped lists
- Get loop starting point
- Calculate loop length

### List Addition (4 tests)
- Add single digit numbers
- Add multi-digit numbers
- Handle carry operations
- Multiple carries

### Y-Bridge Detection (2 tests)
- Detect merge point in intersecting lists
- Verify no merge in separate lists

### Remove Node from Back (5 tests)
- Remove from empty list
- Remove first/middle/last node
- Handle edge cases (beyond list size)

### Edge Cases (4 tests)
- Node constructors
- Tail pointer updates

## Test Results

```
[==========] Running 31 tests from 1 test suite.
[----------] 31 tests from ListTest
...
[----------] 31 tests from ListTest (0 ms total)

[  PASSED  ] 31 tests.
```

## Usage Example

```cpp
#include "List.h"

// Create a list
List list;
list.push_back(Node(1));
list.push_back(Node(2));
list.push_back(Node(3));

// Print the list
list.print();  // Output: 1 2 3

// Reverse the list
list.reverse_iterative();
list.print();  // Output: 3 2 1

// Detect loops
bool hasLoop = List::doesLoopExist(list);

// Add two lists
List a = createListWithValues({1, 2, 3});
List b = createListWithValues({4, 5, 6});
List sum = List::add(a, b);  // 123 + 456 = 579
```

## Key Algorithms Implemented

1. **Floyd's Cycle Detection** - O(n) time, O(1) space
2. **Two-pointer technique** - Remove nth from back
3. **Iterative/Recursive reversal** - Different approaches for interviews
4. **List addition with carry** - Common interview question

## License

This is a learning/interview preparation project.

## Author

Created as part of DSA interview preparation with professional unit testing practices.
