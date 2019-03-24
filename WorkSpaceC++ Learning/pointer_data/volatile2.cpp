/*
 * volatile2.cpp
 *
 *  Created on: 16-Nov-2017
 *      Author: ee205237
 */

#include<iostream>
using namespace std;
int main()
{
	//int const volatile  i = 10;
					//voltile making sure that  latest updated value shold get update
					//EVEN THOUG OPTIMSATION ENABLED
	int const i = 10;
					//COMPILER CHECK  is this value is global or constant it load in to its register
					//nand each time not go for load from memory,so it increase the speed.
    int  *ptr;
    //ptr= &i;
    ptr=const_cast<int *>(&i);
    *ptr= 20;
    cout<<i;
	return 0;
}

