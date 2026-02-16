#!/bin/bash

# Build script for LinkedList with Google Test

echo "Building LinkedList tests..."
g++ -std=c++17 -I/opt/homebrew/include list_test.cpp List.cpp \
    -L/opt/homebrew/lib -lgtest -lgtest_main -pthread -o list_tests

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo ""
    echo "Running tests..."
    echo "==============================================="
    ./list_tests
else
    echo "Build failed!"
    exit 1
fi
