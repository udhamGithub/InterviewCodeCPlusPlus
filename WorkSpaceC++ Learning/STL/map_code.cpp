/*
 * map_code.cpp
 *
 *  Created on: 03-Oct-2017
 *      Author: ee205237
 */

#include<iostream>
#include<map>
using namespace std;
//In set only value is there
//We can asume in set ,that key value is equvalent to value
//map has two value: Value will be associtive with key

	//key and value
	//Key will not be duplicate in map, but in mutimap is there
	//Data will be arrange in tree

	//Push front and push back option is not there,because ,data will be inserted based on ,Binary tree rule.

int main()
{
	map<char ,int> employee;
	map<string ,int> name;
	//First make pair and then insert
	name.insert(pair<string,int>("udham_SinghYadav",10));
	name.insert(pair<string ,int>("AvneeshKumarY",30));
	//check for duplication
	employee.insert (pair<char,int>('a',100));
	employee.insert (pair<char,int>('b',200));
	employee.insert (pair<char,int>('c',300));
	employee.insert (pair<char,int>('d',400));
	employee.insert (pair<char,int>('e',500));

	//pair< map<string ,int>::iterartor,bool> //error
	//return type:
	pair<map<char,int>::iterator,bool> ret;
	ret = employee.insert(pair<char,int>('a',100));
    if(ret.second == false)
    {
    	cout<<"\nElement is already present\n";
    }
    employee.insert(ret.first, pair<char,int>('x',200));

	 std::map <char,int>::iterator it;//=employee.begin();
	 for(it = employee.begin();it!=employee.end();++it)
	 {
		/*cout << it->first  << it->second << '\n';*?
		 *
		 */
		 cout<<"First Data::"<< it->first <<" Second ::" << it->second <<endl;
		 //cout<<
	 }
	 //insert by itrator:
	return 0;
}


