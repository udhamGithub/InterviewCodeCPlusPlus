#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout<<"Base constructor";
	}
};
class Derived1: public Base
{
   int derived1;
public:
   Derived1():derived1(5)
	{
		cout<<"Base constructor";
	}
	void derived1fun()
	{
		cout<<"--"<<derived1;
	}
};

class Derived2: public Base
{
   int derived2;
public:
   Derived2():derived2(5)
	{
		cout<<"derived2 constructor";
	}
	void derived1fun()
	{
		cout<<"--"<< derived2;
	}
};

int main()
{
	Base *bptr=new Derived1;
	//Derived1 *dptr=bptr;

}
