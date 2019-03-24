/*
 * classTemplate.cpp
 *
 *  Created on: 17-Nov-2017
 *      Author: ee205237
 */

#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    Array(T (& arr)[5]);
    void print();
};

template <typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
#if 1
//--------passing refrence has benifit ,we get the size by size of
template<typename T1>
Array<T1>::Array(T1 (& arr)[5])
{
	size= (sizeof(arr))/sizeof(T1); //We will receive total size of array now
							//devide by int ,get the element size in array
	ptr=new T1[size];
	for(int i=0;i<size;i++)
	{
		ptr[i]=arr[i];
	}
}
#endif

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    float arrayb[5]={8.9, 9.0,10,5,0};
    Array<int> a(arr, 5);
    Array<float>b(arrayb,5);
    Array<int>b1(arr);
    Array<float>b2(arrayb);   //we are not able to send dynamic size by refrence also
    //pass by refrence no array decay
    a.print();
    b.print();
    b1.print();
    b2.print();//refrence case
    return 0;
}
