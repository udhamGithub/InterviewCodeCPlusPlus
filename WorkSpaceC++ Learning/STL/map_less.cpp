
#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>    // std::sort, std::includes
#include<map>
using namespace std;

int main ()
{
  int foo[]={10,20,5,15,25};
  int bar[]={15,10,20,0,1,2,3};

  map<const unsigned long long, unsigned long long> *table;
 // sort (foo, foo+5, less<int>());  // 5 10 15 20 25
  sort (bar, bar+7, less<int>());  //   10 15 20
  if (includes (foo, foo+5, bar, bar+3,less<int>()))
	  cout << "foo includes bar.\n";

  for(int i=0;i<7;i++)
  {
	 // cout<<foo[i]<<"  ";
	  cout<<bar[i]<<"  \n";

  }
  return 0;
}




