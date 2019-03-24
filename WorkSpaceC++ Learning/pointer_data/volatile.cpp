/*
 * volatile.cpp
 *
 *  Created on: 16-Nov-2017
 *      Author: ee205237
 */




#include <iostream>
using namespace std;
int main(void)
{
    const int local = 10;
    //int *ptr = (int*) &local;
    int *ptr = const_cast<int*>(&local);
    cout<<"Initial value"<< local;

    *ptr = 100;

    cout<<"Modified value"<< *ptr;

    return 0;
}
