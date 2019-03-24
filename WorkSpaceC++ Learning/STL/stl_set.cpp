#if 0
Operation:on Set contatiner
	1-creating empty setobject
	2-Inserting value to set object
	3-Return value while insertion and -checking pair value
	4-Insertion irespective of iteration location,data will be insert in acending order
	5-Objct create from another object(copyinmg)
	6-Objct create from another aRRAY(copyinmg)
	7-Passing range value while creating object TAKING VALUE FROM ANOTHER OBJECT
#endif
#if 0
-Each container provide the iterator
-So we can acess iterator class,and get declare iterator pointer
		conatiner<datatype>::iterator itr;
		list<int>::iterator itr1;
-insertion return type is  pair type , pair has two data,first has "container, iterator type"
		another is bool type

		e.g pair<conatiner<datatype>::iterator,bool>
			pair<list<int>::iterator,bool>
#endif
#include<iostream>
#include<set>
using namespace std;
#if 0
//	/http://www.cplusplus.com/reference/list/list/list/
//  Reference
//  Example look anoter
//In set only value is there ,not associated key with value ,unlike map
//We can assume in set ,that key value is equivalent to value,so set also come under
//assocaitive(assocition relation b/w two data)container
//No duplication--data in set
//multiset has duplication

//map has two value: Value will be associative with key
		//key and value
		//Key will not be duplicate in map, but in mutimap is there
//Data will be arrange in tree
//Push front and push back option is not there,because ,data will be inserted based on
//,Binary tree rule.
#endif
bool fncomp (int lhs, int rhs)
{ return lhs<rhs;}
struct classcomp
{
  bool operator() (const int& lhs, const int& rhs) const
  {
	  return lhs<rhs;
  }
};


int main()
{
	//-creating empty set object
	set<int> Player1,Player2;
    //Inserting value to set object
	Player1.insert(10);
	Player1.insert(1);
	Player1.insert(12);
	Player1.insert(5);
	Player1.insert(14);
	//No need to sort already sorted
	set<int>::iterator itr1;
	cout<<"Player Data1\n";
	for(itr1= Player1.begin();itr1 != Player1.end();itr1++)
	{
		cout<<" "<< (*itr1) ;  //we can derefrence
	}
#if 1
	//Return value while insertion and -checking error pair value
	set<int>::iterator it;
	pair<set<int>::iterator,bool> ret;
	ret= Player1.insert(10);
	if(ret.second== NULL)
	{
		cout<<"\nPlayer1 Duplication data trying to insert\n";
	}
	//Insertion at given iteration location,data will be insert in accending
	//order only irespective given location
	it =ret.first;
	Player1.insert(it,0);
	cout<<"Player1Data, insertion at given location:after 10 but it come in proper order based on BST rule \n";
	for(it= Player1.begin() ;it!= Player1.end();it++)
	{
		cout<<" "<<*it;
	}
#endif
	//5-Objct create from another object(copyinmg)
	//6-Objct create from another aRRAY(copyinmg)
	set<int> first;
	int myInarray[]= {10,20,30,40,50};
	set<int> second (myInarray,myInarray+5);
	set<int>::iterator itx;
	cout<<"\nSet Objct created from another aRRAY..data is\n";
	for(itx= second.begin();itx!=second.end();itx++)
	{
		cout<<"  "<<*itx;
	}
	//object copy
	cout<<"\nobj3 copy from  from another object range data\n";
	set<int> obj3(second);
	for(itx= obj3.begin();itx!=obj3.end();itx++)
	{
		cout<<"  "<<*itx;
	}
	cout<<"\nobj4 copy from  from another object range value \n";
	set<int> obj4(second.begin(),second.end());
	for(itx= obj4.begin();itx!=obj4.end();itx++)
	{
		cout<<"  "<<*itx;
	}

	// class as Compare---Not yet understand properly
	set<int,classcomp> fifth;
	bool(*fn_pt)(int,int) = fncomp;
	// function pointer as Compare
	std::set<int,bool(*)(int,int)> sixth (fn_pt);
	return 0;
}





