/*
 * smart_pointer.cpp
 *
 *  Created on: 24-Nov-2017
 *      Author: ee205237
 */

#include<iostream>
using namespace std;
template <typename T1>
class SmartPtr
{
   T1 *ptr;  // Actual pointer
public:
   // Constructor: Refer http://www.geeksforgeeks.org/g-fact-93/
   // for use of explicit keyword
    SmartPtr(T1 *p = NULL) { ptr = p; }

   // Destructor
   ~SmartPtr()
   {
	   delete(ptr);
   }
   // Overloading dereferencing operator
   T1 &operator *()
   {
	   return *ptr;
   }
   T1 * operator -> ()
   {
	   return ptr;
   }

};

int main()
{

    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;

    int *ptr1;
    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, destructor for it is automatically
    // called and destructor does delete ptr.
    {
    	int a=10;
    	ptr1=&a;
    }
    cout<<*ptr1;
    return 0;
}


