/*
 * exception.cpp
 *
 *  Created on: 13-Nov-2017
 *      Author: ee205237
 */
#include<iostream>
using namespace std;
int devide(int a, int b);
int main()
{

	int  result=0;
	int  i=10;

	try
	{
		result=devide(2,0);
		cout<<result;
	}
	catch(int x)
	{
			cout<<"DevideByZero";
	}
	catch(const char *msg)
	{
		cerr<< msg;
	}
}
int devide(int a, int b)
{
	int x=1;
	int result;
	if(b==0)
	{
		throw "zero";
	}
	return result = a/b;
}

//diffrent case:
	//-
	//-
	//-




