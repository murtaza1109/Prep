#include "StringDemo.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

StringDemo::StringDemo() {}

// ---------------------------------------------------------------------------
// std::string  (= std::basic_string<char>)
//   - Dynamic character array with rich text operations.
//   - NOT built on std::vector — it is its own self-contained container.
//   - Short String Optimization (SSO): strings up to ~15 chars are stored
//     directly inside the object (no heap allocation at all).
//   - Supports random-access iterators, same as vector.
//   - Contiguous memory: &s[0] is a valid char array.
//   - std::wstring  = basic_string<wchar_t>  (wide chars)
//   - std::u8string = basic_string<char8_t>  (UTF-8, C++20)
// ---------------------------------------------------------------------------
void StringDemo::demo()
{
    cout << "\n========== std::string ==========\n";

    // --- Construction ---
    string s1 = "Hello";               // from string literal
    string s2("World");                // constructor
    string s3(5, '*');                 // "****" — repeat char N times
    string s4 = s1;                    // copy
    string s5 = s1 + ", " + s2 + "!"; // concatenation with +

    cout << "s1        : " << s1 << "\n";
    cout << "s3        : " << s3 << "\n";
    cout << "s5        : " << s5 << "\n";

    // --- Size and capacity ---
    cout << "\nsize()    : " << s5.size()     << "\n"; // number of chars
    cout << "length()  : " << s5.length()   << "\n"; // same as size()
    cout << "capacity(): " << s5.capacity() << "\n"; // allocated space
    cout << "empty()   : " << s5.empty()    << "\n";

    // --- Element access ---
    cout << "\nElement access:\n";
    cout << "s5[0]     : " << s5[0]       << "\n"; // no bounds check
    cout << "s5.at(1)  : " << s5.at(1)    << "\n"; // throws out_of_range
    cout << "front()   : " << s5.front()  << "\n";
    cout << "back()    : " << s5.back()   << "\n";
    cout << "c_str()   : " << s5.c_str()  << " (null-terminated C string)\n";

    // --- Modification ---
    cout << "\nModification:\n";
    string t = "Hello";
    t += " World";           // append with +=
    t.append("!!!");         // append with method
    cout << "After += and append(): " << t << "\n";

    t.push_back('?');        // append single char
    cout << "After push_back('?'): " << t << "\n";

    t.pop_back();            // remove last char
    cout << "After pop_back():     " << t << "\n";

    t.insert(5, ",");        // insert at index 5
    cout << "After insert(',') at 5: " << t << "\n";

    t.erase(5, 1);           // erase 1 char at index 5
    cout << "After erase at 5:       " << t << "\n";

    t.replace(6, 5, "C++");  // replace 5 chars starting at 6 with "C++"
    cout << "After replace:         " << t << "\n";

    // --- Searching ---
    cout << "\nSearching:\n";
    string text = "apple banana cherry banana";
    size_t pos = text.find("banana");         // first occurrence
    cout << "find(\"banana\")      : " << pos << "\n";

    size_t pos2 = text.rfind("banana");       // last occurrence
    cout << "rfind(\"banana\")     : " << pos2 << "\n";

    size_t notFound = text.find("mango");
    cout << "find(\"mango\")       : "
         << (notFound == string::npos ? "not found (string::npos)" : "found") << "\n";

    // --- Substrings ---
    cout << "\nSubstrings:\n";
    string sub = text.substr(6, 6);  // start at index 6, length 6
    cout << "substr(6, 6): \"" << sub << "\"\n";

    // --- Comparison ---
    cout << "\nComparison:\n";
    string a = "apple", b = "banana";
    cout << "(a == b) : " << (a == b) << "\n";
    cout << "(a <  b) : " << (a < b)  << " (lexicographic)\n";
    cout << "a.compare(b) : " << a.compare(b) << " (negative = a comes first)\n";

    // --- Iterators (random-access, same as vector) ---
    cout << "\nIteration:\n";
    string word = "hello";
    cout << "Forward:  ";
    for (auto it = word.begin(); it != word.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "Reverse:  ";
    for (auto it = word.rbegin(); it != word.rend(); ++it)
        cout << *it << " ";
    cout << "\n";

    // Works with std algorithms
    sort(word.begin(), word.end());
    cout << "After sort(): " << word << "\n";

    // --- Conversion to/from numbers ---
    cout << "\nConversions:\n";
    int  num  = stoi("42");         // string → int
    double d  = stod("3.14");       // string → double
    string ns = to_string(12345);   // number → string
    cout << "stoi(\"42\")       = " << num  << "\n";
    cout << "stod(\"3.14\")     = " << d    << "\n";
    cout << "to_string(12345) = " << ns   << "\n";

    // --- Short String Optimization (SSO) ---
    // Small strings live inside the string object itself (no heap alloc).
    // Threshold is implementation-defined — typically 15-22 chars in libc++.
    cout << "\n-- Short String Optimization (SSO) --\n";
    string shortStr = "Hi";           // stored on stack — no heap alloc
    string longStr  = "This is a longer string that exceeds SSO threshold";
    cout << "Short str size=" << shortStr.size()
         << "  capacity=" << shortStr.capacity() << " (SSO: no heap alloc)\n";
    cout << "Long  str size=" << longStr.size()
         << "  capacity=" << longStr.capacity() << " (heap allocated)\n";
}
