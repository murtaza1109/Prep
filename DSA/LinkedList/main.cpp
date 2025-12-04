#include <iostream>

#include "List.h"

using namespace std;

int main()
{
//    List<int> myList;

//    for(int i=0;i<10;i++)
//    {
//        myList.push_back(Node<int>(i));
//    }

    //myList.print();

    //myList.reverse_iterative();
    //myList.print();

//    myList.reverse_recursive();
//    myList.print();

//    List<int> loopedList = List<int>::createLoopedList(5);

//    cout << "1. " << (List<int>::doesLoopExist(loopedList) ? "Loop exists" : "Loop does not exist") << endl;
//    cout << "2. " << (List<int>::doesLoopExist(myList) ? "Loop exists" : "Loop does not exist") << endl;

//    List<int> loopedList2 = List<int>::createLoopedList(5);

//    if(List<int>::doesLoopExist(loopedList2))
//    {
//        cout << "Loop starting point : " << List<int>::getLoopStartingPoint(loopedList2)->data << endl;
//        cout << "Loop length : " << List<int>::calculateLoopLength(loopedList2) << endl;
//    }

    List<int> a;
    List<int> b;

    a.push_back(3);
    a.push_back(5);
    a.push_back(1);

    b.push_back(6);
    b.push_back(7);
    b.push_back(5);

    List<int> sum = List<int>::add(a,b);

    sum.print();

    return 0;
}
