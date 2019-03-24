#include<iostream>
#include<memory>
#include<string>
using namespace std;

class Child;
class Parent
{
	int a;
	string name_p;
	//shared_ptr<Child> objChildPointer;
	weak_ptr<Child> objChildPointer;
	int static data_count;
public:
	Parent(string name_p)
    {
		data_count=data_count+1;
		cout<<"\nParent constructure---- :"<<name_p<<"     obj_count"<<data_count<<endl;
    }
	~Parent()
	{
		cout<<"\n~Distructure Parent called for Obj"<<name_p<<"    obj_count"<<data_count<<endl;
		data_count --;
	}
	void setChild(shared_ptr<Child> objdata)
	{	cout<<"child set\n";
		objChildPointer=objdata;
	}
};

class Child
{
	string l_childName;
	int static child_count;
	shared_ptr<Parent> m_mother;
	shared_ptr<Parent> m_father;
public:
	Child()
	{

	}
	Child(string name_p)
	{
		child_count++;
		l_childName = name_p;
		cout<<"\n child constructor for child:"<< name_p <<"  count" <<child_count<<endl;
	}

	Child(string name_p,shared_ptr<Parent> mother,shared_ptr<Parent> father)
	{
		child_count++;
		cout<<"\n child constructor for child:"<< name_p <<"  count" <<child_count<<endl;

		l_childName = name_p;
		m_mother=  mother;
		m_father=father;
		cout<<"l_childName::"<<name_p<<endl;
	}

	~Child()
	{
		cout<<"\n child distructor for obj:"<<l_childName << child_count<<endl;
		child_count --;
	}
};
int Child::child_count;
int Parent:: data_count;

int main()
{
//Each pointer object are owner of underlying pointer:refrence count is maintained
	shared_ptr<Parent> FatherObj(new Parent("KSY"));
	shared_ptr<Parent> motherObjPointer(new Parent("Savitri"));
	shared_ptr<Child>obj3(new Child("Avneesh",FatherObj,motherObjPointer));
//------------------------------------------------------
	cout<<"\nAdress::Father "<<FatherObj.get();
	cout<<"\n :::----------------object3  have father mother boject dependecncy\n";
	FatherObj->setChild(obj3);
	motherObjPointer->setChild(obj3);

//do alternate changes in parent class and seethe result
	//shared_ptr<Child> objChildPointer;
	//weak_ptr<Child> objChildPointer;
}
