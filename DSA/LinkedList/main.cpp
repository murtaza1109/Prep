#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

#include "List.h"

using namespace std;

#define printFnName     cout << __func__ << endl;

List<int> createList(bool print=true)
{
    printFnName

    List<int> myList;

    for(int i=0;i<10;i++)
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

    List<int> a = createList();
    List<int> b = createList();

    a.reverse_iterative();
    a.print();

    b.reverse_recursive();
    b.print();
}

void detectLoop()
{
    printFnName

    List<int> list = createList();
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

    List<int> a = createList();
    List<int> b = createList();

    List<int> sum = List<int>::add(a,b);

    sum.print();
}

int main()
{

    std::srand(std::time(nullptr));

    reverse();

    detectLoop();
    loopStartPoint();
    loopLength();

    sum();

    return 0;
}
