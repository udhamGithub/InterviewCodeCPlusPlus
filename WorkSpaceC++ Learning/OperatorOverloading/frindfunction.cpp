/*
 * frindfunction.cpp
 *
 *  Created on: 17-Nov-2017
 *      Author: ee205237
 */
#include<iostream>
using namespace std;

class y
{
	int salary;
	char * name;
public:
	y(int x=0)
	{
		salary=x;
	}
};

class AB
{
	int salary;

public:
	AB(int i=0)
	{
		salary= i;
	}
	friend int incometax(AB salary);

	AB & operator = (AB& obj);
	{
		salary=obj.salary;
	}
};

int incometax(AB data)
{
	int tax =0;
	tax =(data.salary)/100;
	return tax;
}

int main()
{
	AB obj1(10000) ,obj2(10000);
	obj1 =obj2; //obj1.operator = (obj2);

	incometax(obj1);

	return 0;
}



