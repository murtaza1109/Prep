#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

#include "List.h"

using namespace std;

#define printFnName     cout << __func__ << endl;

List<int> createList(int size, bool print=true)
{
    printFnName

    List<int> myList;

    for(int i=0;i<size;i++)
    {
        myList.push_back(Node<int>(std::rand() % 10));
    }

    if(print)
    {
        myList.print();
    }

    return myList;
}

List<int> createLoopedList()
{
    printFnName

    List<int> myList = List<int>::createLoopedList(5);;

    return myList;
}

void reverse()
{
    printFnName

    List<int> a = createList(10);
    List<int> b = createList(10);

    a.reverse_iterative();
    a.print();

    b.reverse_recursive();
    b.print();
}

void detectLoop()
{
    printFnName

    List<int> list = createList(10);
    List<int> loopedList = createLoopedList();

    cout << "1. " << (List<int>::doesLoopExist(list) ? "Loop exists" : "Loop does not exist") << endl;
    cout << "2. " << (List<int>::doesLoopExist(loopedList) ? "Loop exists" : "Loop does not exist") << endl;

}

void loopStartPoint()
{
    printFnName

    List<int> loopedList = createLoopedList();

    if(List<int>::doesLoopExist(loopedList))
    {
        cout << "Loop starting point : " << List<int>::getLoopStartingPoint(loopedList)->data << endl;
    }
}

void loopLength()
{
    printFnName

    List<int> loopedList = createLoopedList();

    if(List<int>::doesLoopExist(loopedList))
    {
        cout << "Loop length : " << List<int>::calculateLoopLength(loopedList) << endl;
    }
}

void sum()
{
    printFnName

    List<int> a = createList(3);
    List<int> b = createList(3);

    List<int> sum = List<int>::add(a,b);

    sum.print();
}

void detectYBridge()
{
    printFnName

    List<int> a,b;

    List<int>::createYBridgeList(a,b);

    cout << "------------Y bridge List 1------------------" << endl;
    a.print();
    cout << "------------Y bridge List 2------------------" << endl;
    b.print();

    cout << "1. " << ((List<int>::doesYBridgeExist(a,b)==nullptr) ? "Y bridge does not exists" : "Y bridge exists") << endl;

    cout << "------------Normal List 1------------------" << endl;
    List<int> c = createList(10);
    cout << "------------Normal List 2------------------" << endl;
    List<int> d = createList(10);

    cout << "1. " << ((List<int>::doesYBridgeExist(c,d)==nullptr) ? "Y bridge does not exists" : "Y bridge exists") << endl;
}

void removeNthFromBack()
{
    List<int> a = createList(10);

    a.removeNodeFromBack(5);
    a.print();
}

int main()
{

    std::srand(std::time(nullptr));

//    reverse();

//    detectLoop();
//    loopStartPoint();
//    loopLength();

//    sum();

//    detectYBridge();

    removeNthFromBack();

    return 0;
}
