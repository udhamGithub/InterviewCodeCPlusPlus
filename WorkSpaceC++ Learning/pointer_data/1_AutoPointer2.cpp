#include<iostream>
#include<memory>
using namespace std;
class A
{
	int a;
	int b;
public:
	A()
	{
		a=10;
		b=20;
		cout<<"\nConstructure";
	}
	~A()
	{
		cout<<"\n ~ distructor called";
	}
	void show()
	{
		cout<<"\nDisplay Data"<<endl;
	}
};

int main()
{
	//undefined reference to `__gcov_init'
	//unique_ptr<A> ptr1 (new A);
	//use this  -std=c++11 in below path  for unique pointer
	//c/c++build->Cross G++compiler->mislaneous_>otherflags ->-std=c++11
#if 1
	auto_ptr<A> ptrObj(new A),ptrObj2,ptrObj3;
	ptrObj->show();
	cout<<"\nAdress ptrObj::"<< ptrObj.get();

	ptrObj2 = ptrObj;
	ptrObj2->show();
	ptrObj->show();
	cout<<"\nAdress ptrObj:after assignment to 2:"<< ptrObj.get();
	cout<<"\nAdress ptrObj2::"<< ptrObj2.get();

	ptrObj3=ptrObj2;
	cout<<"\nAdress ptrObj2:After assign to 3:"<< ptrObj2.get();
	ptrObj2->show();
	cout<<"\nAdress::ptrObj3"<< ptrObj3.get();
#endif
	return 0;
}



