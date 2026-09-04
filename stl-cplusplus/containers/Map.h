#ifndef MAP_H
#define MAP_H

// std::map — ordered associative container (key → value pairs)
// Keys are unique and kept sorted (uses a Red-Black Tree internally).
// All operations (insert, find, erase) are O(log n).
// Header: <map>

class Map
{
public:
    Map();
    static void demo();
};

#endif // MAP_H
