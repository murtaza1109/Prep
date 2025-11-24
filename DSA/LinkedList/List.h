#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;

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

private:
    Node<T>* head;


    Node<T>* findEnd();

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
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

template <typename T>
Node<T>* List<T>::findEnd()
{
    Node<T>* end = head;

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

#endif // LIST_H
