/*
 * pointer.cpp
 *
 *  Created on: 16-Nov-2017
 *      Author: ee205237
 */

#include <iostream>
using namespace std;

int fun(int* ptr)
{
	*ptr = *ptr + 10;
	return (*ptr);
}

int main(void)
{
	const int val = 10;
	const int *ptr = &val;
	int *ptr1 = const_cast <int *>(ptr);
	fun(ptr1);
	cout<< val;
	return 0;
}
