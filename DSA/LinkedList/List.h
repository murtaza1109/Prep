#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory.h>

using namespace std;

template <typename T>
struct Node {

    T data;
    Node* next;

    Node() :
        data(0),
        next(nullptr)
    {

    }

    Node(const T& value) :
        data(value),
        next(nullptr)
    {

    }
};

template <typename T>
class List
{
public:

    List();

    void push_back(Node<T> value);
    void print();
    void reverse_iterative();
    void reverse_recursive();
    bool doesLoopExist();

private:
    Node<T>* head;

    Node<T>* findEnd();
    Node<T> *reverse_recursive(Node<T>* node);

};

template <typename T>
List<T>::List() :
    head(nullptr)
{
}

template <typename T>
void List<T>::push_back(Node<T> value)
{
    Node<T>* newNode = new Node<T>(value.data);
    Node<T>* end = findEnd();

    if(end == nullptr)
    {
        head = newNode;
    }
    else
    {
        end->next = newNode;
    }
}

template <typename T>
void List<T>::print()
{
    Node<T>* temp = head;

    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

template<typename T>
void List<T>::reverse_iterative()
{
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

template<typename T>
void List<T>::reverse_recursive()
{
    head = reverse_recursive(head);
}

template <typename T>
Node<T>* List<T>::reverse_recursive(Node<T>* node)
{
    if(!node || !node->next)
    {
        return head;
    }

    Node<T>* newHead = reverse_recursive(node->next);
    node->next->next = node;
    node->next = nullptr;

    return newHead;
}

template <typename T>
Node<T>* List<T>::findEnd()
{
    Node<T>* end = std::move(head);

    if(end == nullptr)
    {
        return nullptr;
    }

    while(end->next)
    {
        end = end->next;
    }

    return end;
}

template <typename T>
bool List<T>::doesLoopExist()
{
    bool loopDetected = false;
    Node<T>* slowPtr = head;
    Node<T>* fastPtr = head;

    while(fastPtr || fastPtr->next)
    {
        slowPtr = slowPtr->next;
        if(slowPtr == fastPtr)
        {
            loopDetected = true;
            break;
        }

        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr)
        {
            loopDetected = true;
            break;
        }
    }
    return loopDetected;
}

#endif // LIST_H
