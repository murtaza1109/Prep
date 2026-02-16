#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory.h>

using namespace std;

struct Node {

    int data;
    Node* next;

    Node();
    Node(const int& value);
};

class List
{
public:

    List();

    Node *push_back(Node value);
    void print();
    void reverse_iterative();
    void reverse_recursive();

    static List createLoopedList(int pos);
    static bool doesLoopExist(List list);
    static Node* getLoopStartingPoint(List list);
    static int calculateLoopLength(List list);

    static List reverse(List list);
    static List add(List a, List b);

    static void createYBridgeList(List& a, List& b);
    static Node *doesYBridgeExist(const List& a, const List& b);

    void removeNodeFromBack(int n);


    int count{0};
    Node* head;
    Node* tail;

private:
    Node* findEnd();
    Node *reverse_recursive(Node* node);

};

#endif // LIST_H
























