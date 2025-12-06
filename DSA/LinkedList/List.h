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

    Node<T> *push_back(Node<T> value);
    void print();
    void reverse_iterative();
    void reverse_recursive();

    static List<T> createLoopedList(int pos);
    static bool doesLoopExist(List list);
    static Node<T>* getLoopStartingPoint(List list);
    static int calculateLoopLength(List list);

    static List reverse(List list);
    static List<T> add(List a, List b);

    static void createYBridgeList();


    int count{0};
    Node<T>* head;
    Node<T>* tail;

private:
    Node<T>* findEnd();
    Node<T> *reverse_recursive(Node<T>* node);

};

template <typename T>
List<T>::List() :
    head(nullptr)
{
}

template <typename T>
Node<T>* List<T>::push_back(Node<T> value)
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
    tail = newNode;

    return newNode;
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
    cout << endl;
}

template<typename T>
void List<T>::reverse_iterative()
{
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while(current)
    {
        // save next before reversing the link
        next = current->next;

        //reverse the link
        current->next = prev;

        //update for next loop
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
        return node;
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

template<typename T>
List<T> List<T>::createLoopedList(int pos)
{
    Node<T>* midNode;
    List <T> list;
    for(int i=0;i<pos*2;i++)
    {
        if(i==pos)
        {
            midNode = list.push_back(i);
        }
        else
        {
            list.push_back(i);
        }
    }

    list.tail->next = midNode;

    return list;
}

template <typename T>
bool List<T>::doesLoopExist(List list)
{
    return !(getLoopStartingPoint(list)==nullptr);
}

template<typename T>
Node<T> *List<T>::getLoopStartingPoint(List list)
{
    if(!list.head) return nullptr;

    Node<T>* slowPtr = list.head;
    Node<T>* fastPtr = list.head;

    while(fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr)
        {
            return slowPtr;
        }
    }

    return nullptr;
}

template<typename T>
int List<T>::calculateLoopLength(List list)
{
    Node<T>* startingPoint = getLoopStartingPoint(list);
    int length = 0;

    if(startingPoint)
    {
        Node<T>* temp = startingPoint;

        //kickstart
        temp = temp->next;
        length++;

        while(temp!=startingPoint)
        {
            temp = temp->next;
            length++;
        }
    }

    return length;
}

template<typename T>
List<T> List<T>::reverse(List list)
{
    Node<T>* p = nullptr;
    Node<T>* c = list.head;
    Node<T>* n = nullptr;

    while(c)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    list.head = p;
    return list;
}

template<typename T>
List<T> List<T>::add(List a, List b)
{
    List aReverse = reverse(a);
    List bReverse = reverse(b);
    List sumList;

    int d1,d2;
    int carry = 0;
    int sum;

    Node<T>* aPtr = aReverse.head;
    Node<T>* bPtr = bReverse.head;

    while(aPtr || bPtr)
    {
        if(aPtr)
        {
            d1 = aPtr->data;
            aPtr = aPtr->next;
        }
        else d1=0;

        if(bPtr)
        {
            d2 = bPtr->data;
            bPtr = bPtr->next;
        }
        else d2=0;

        sum = (d1+d2+carry)%10;
        carry = (d1+d2+carry)>9?1:0;
        sumList.push_back(Node<T>(sum));
    }

    if(carry) sumList.push_back(Node<T>(carry));

    sumList.reverse_iterative();

    return sumList;
}

#endif // LIST_H
