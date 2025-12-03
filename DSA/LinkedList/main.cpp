#include <iostream>

#include "List.h"

using namespace std;

int main()
{
    List<int> myList;

    for(int i=0;i<10;i++)
    {
        myList.push_back(Node<int>(i));
    }

    //myList.print();

    //myList.reverse_iterative();
    //myList.print();

//    myList.reverse_recursive();
//    myList.print();

    List<int> loopedList = List<int>::createLoopedList(5);

    loopedList.print();

    cout << "1. " << (List<int>::doesLoopExist(loopedList) ? "Loop exists" : "Loop does not exist") << "\n";
    cout << "2. " << (List<int>::doesLoopExist(myList) ? "Loop exists" : "Loop does not exist") << "\n";

    return 0;
}
