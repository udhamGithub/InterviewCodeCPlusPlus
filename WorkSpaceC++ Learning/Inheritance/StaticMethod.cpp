
#include<iostream>
using namespace std;

class A
{
public:
	void add(int x)
	{
		cout<<"class A";
	}

};
class B
{
public:
	void add(int x)
	{
			cout<<"class A";
	}
};
class t:virtual  public A,virtual public B
{
	public:
	void data()
	{
		cout<< "show data";
	}
};


int main()
{
    t obj;
    obj.A::add(2);
	return 0;
}
