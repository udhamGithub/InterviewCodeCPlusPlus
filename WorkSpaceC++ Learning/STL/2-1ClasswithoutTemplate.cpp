#include <iostream>
using namespace std;

class Array
{
private:
    int *ptr;
    int size;
public:
   // Array(int arr[], int s);
    Array(int (& arr)[5]);
    void print();
};
//--------passing refrence has benifit ,we get the size by size of

Array ::Array(int (&arr)[5])
{
	size=(sizeof(arr))/sizeof(int);
	ptr=new int[size];
	for(int i=0;i<size;i++)
	{
		ptr[i]=arr[i];
	}
}

void Array::print()
{
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Array  a(arr);
    a.print();
    return 0;
}
