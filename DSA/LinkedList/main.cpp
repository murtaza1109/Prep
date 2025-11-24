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

    myList.print();

    return 0;
}
