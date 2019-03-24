/*
 * SimpleObj.cpp
 *
 *  Created on: 09-Oct-2017
 *      Author: ee205237
 */
#include<iostream>
using namespace std;
class absent
{
	 int a;
public:
	 absent()
	 {
		a=10;
		cout<<"Default constructure:";
	 }
	 absent(absent &data)
	 {	 a=20;
		 cout<<"copy constructor";
	 }
	 void  operator =(const absent & obj)
	 {
		 cout<<"Assignment operator:0----";
	 }
};

int main()
{

	absent obj1,obj2;
	obj2=obj1;

	return 0;
}



