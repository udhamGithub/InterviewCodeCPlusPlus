
#include<iostream>
#include<memory>
using namespace std;
class A
{
	int a;
	int static data_count;
public:
	A()
    {
		  cout<<"\nconstructure---- A\n";
		  data_count=data_count+1;
		  cout<<"\nObject Created: "<< data_count;
	}
	void getdata()
	{
		cout<<"\n A-Data is :"<< a<<endl;
	}
	~A()
	{
		cout<<"\n~Distructure called for Obj"<< data_count <<endl;
		data_count --;
	}

};

int A:: data_count;

int main()
{
	//Each pointer object are owner of underlying pointer:
	//refrence count is maintained
	shared_ptr<A> ptrObj(new A),ptrObj2;
	ptrObj->getdata();
	//ptrObj2= move(ptrObj);  // this call is valid?->yes but out put will be as diffrent,
								//ptrObj2 will get complete ownership from ptrob,and make that null
	ptrObj2= ptrObj;
	cout<<"\n Shared pointer example";
	cout<<"\nAdress::ptrObj2 "<<ptrObj2.get();
	cout<<"\nAdress::ptrObj "<<ptrObj.get();
	//---------------------------------------
	shared_ptr<A> ptrObj4(new A);

}
