#include "List.h"
#include <cstdlib>

// Node constructors
Node::Node() :
    data(0),
    next(nullptr)
{
}

Node::Node(const int& value) :
    data(value),
    next(nullptr)
{
}

// List constructor
List::List() :
    head(nullptr),
    tail(nullptr)
{
}

Node* List::push_back(Node value)
{
    Node* newNode = new Node(value.data);
    Node* end = findEnd();

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

void List::print()
{
    Node* temp = head;

    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void List::reverse_iterative()
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

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

void List::reverse_recursive()
{
    head = reverse_recursive(head);
}

Node* List::reverse_recursive(Node* node)
{
    if(!node || !node->next)
    {
        return node;
    }

    Node* newHead = reverse_recursive(node->next);
    node->next->next = node;
    node->next = nullptr;

    return newHead;
}

Node* List::findEnd()
{
    Node* end = std::move(head);

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

List List::createLoopedList(int pos)
{
    Node* midNode;
    List list;
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

bool List::doesLoopExist(List list)
{
    return !(getLoopStartingPoint(list)==nullptr);
}

Node* List::getLoopStartingPoint(List list)
{
    if(!list.head) return nullptr;

    Node* slowPtr = list.head;
    Node* fastPtr = list.head;

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

int List::calculateLoopLength(List list)
{
    Node* startingPoint = getLoopStartingPoint(list);
    int length = 0;

    if(startingPoint)
    {
        Node* temp = startingPoint;

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

List List::reverse(List list)
{
    Node* p = nullptr;
    Node* c = list.head;
    Node* n = nullptr;

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

List List::add(List a, List b)
{
    List aReverse = reverse(a);
    List bReverse = reverse(b);
    List sumList;

    int d1,d2;
    int carry = 0;
    int sum;

    Node* aPtr = aReverse.head;
    Node* bPtr = bReverse.head;

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
        sumList.push_back(Node(sum));
    }

    if(carry) sumList.push_back(Node(carry));

    sumList.reverse_iterative();

    return sumList;
}

void List::createYBridgeList(List &a, List &b)
{
    Node* temp;

    for(int i=0;i<10;i++)
    {
        a.push_back(Node(std::rand() % 10));
        if(i==5)
        {
            temp = a.tail;
        }
    }

    for(int i=0;i<20;i++)
    {
        b.push_back(Node(std::rand() % 10));
    }

    b.tail->next = temp;
}

Node* List::doesYBridgeExist(const List &a, const List &b)
{
    Node* p1 = a.head;
    Node* p2 = b.head;

    while(p1!=p2)
    {
        p1 = (p1==nullptr) ? b.head : p1->next;
        p2 = (p2==nullptr) ? a.head : p2->next;
    }

    return p1;
}

void List::removeNodeFromBack(int n)
{
    if(!head || n <= 0) return;

    Node* leadingPtr = head;
    Node* trailingPtr = head;

    // Move leadingPtr n steps ahead
    for(int i=0;i<n;i++)
    {
        if(!leadingPtr) return; // n is larger than list size
        leadingPtr = leadingPtr->next;
    }

    // If leadingPtr is null, we need to remove the head
    if(leadingPtr==nullptr)
    {
        Node* nodeToRemove = head;
        head = head->next;
        delete nodeToRemove;
        return;
    }

    // Move both pointers until leadingPtr reaches the end
    while(leadingPtr->next)
    {
        leadingPtr = leadingPtr->next;
        trailingPtr = trailingPtr->next;
    }

    // Remove the node after trailingPtr
    Node* nodeToRemove = trailingPtr->next;
    trailingPtr->next = trailingPtr->next->next;
    delete nodeToRemove;
}
