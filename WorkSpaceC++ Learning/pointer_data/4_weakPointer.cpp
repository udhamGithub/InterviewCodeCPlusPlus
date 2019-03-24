
#include<iostream>
#include<memory>
using namespace std;
class A
{
	int a;
public:
	A(){cout<<"conste A";}
	void getdata()
	{
		cout<<"A-Data"<< a;
	}
	~A()
	{
		cout<<"\n~Distructure called";
	}

};

int main()
{
	//Each pointer object are owner of underlying pointer:
	//refrence count is maintained
	shared_ptr<A> ptrObj(new A),ptrObj2;
	ptrObj->getdata();

	weak_ptr<A> ptrObj3=ptrObj;


	//ptrObj2= ptrObj; //in auto pointer it is valid but not in unique pointer
						//autopointer is depricted in std= c++11
	//ptrObj2= move(ptrObj);

	ptrObj2= ptrObj;
	cout<<"\n Unique pointer example";
	cout<<"\nAdress::ptrObj2 "<<ptrObj2.get();
	cout<<"\nAdress::ptrObj "<<ptrObj.get();
}
