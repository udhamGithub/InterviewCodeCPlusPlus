/*
 * contant_cast.cpp
 *
 *  Created on: 16-Nov-2017
 *      Author: ee205237
 */

#if 0
  const_cast is considered safer than simple type casting.as here type is check ,simply not typecast
#endif

#include <iostream>
using namespace std;

int fun(int* ptr)
{
	*ptr = *ptr + 10;
	return (*ptr);
}

int main()
{
	int a1 = (254-65);
	const int* b1 = &a1;
	char* c1= (char*)b1;  //simple type casting
	//char* c2 = const_cast <char *> b1; //compiler error
	//
	const int B=20;
	int * dptr = (int*)B ;
	int * dptr2 = const_cast<int*>B;

	//*c1 = 'B';
	cout<< *c1;

	return 0;
}





