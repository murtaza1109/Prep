#include <iostream>
#include "List.h"

using namespace std;

// This file is now just for demos/manual testing
// All unit tests are in list_test.cpp using Google Test

int main()
{
    cout << "LinkedList Demo - See list_test.cpp for comprehensive unit tests" << endl;
    cout << "=============================================================\n" << endl;
    
    // Simple demo
    List list;
    cout << "Creating list with values: 1, 2, 3, 4, 5" << endl;
    list.push_back(Node(1));
    list.push_back(Node(2));
    list.push_back(Node(3));
    list.push_back(Node(4));
    list.push_back(Node(5));
    
    cout << "Original list: ";
    list.print();
    
    cout << "\nReversing list..." << endl;
    list.reverse_iterative();
    cout << "Reversed list: ";
    list.print();
    
    cout << "\n=============================================================\n";
    cout << "Run unit tests with: ./LinkedList (after building)" << endl;
    cout << "Or build and run tests from Qt Creator" << endl;

    return 0;
}
