#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#define NUM_THREADS 5

typedef struct t_data
{
	int a;
	char *ptr;
}t_data;


void *PrintHello(void *threadid)
{
	t_data  *mydata;
	mydata = (t_data*)threadid;




  // while(1)
   {
	   cout << "\nHello World! Thread ID,= " << mydata->a << endl;
	   cout << "\n Messsage is :,= " << mydata->ptr << endl;
	  // sleep(1);
   }
   pthread_exit(NULL);
}

int main ()
{
   pthread_t threads[NUM_THREADS];
   t_data tdata[NUM_THREADS];
   int rc;
   int i;
   for( i = 0; i < NUM_THREADS; i++ )
   {
	   tdata[i].a= i;
	   tdata[i].ptr="Message is enjoy thread";

      cout << "\nmain() : creating thread,== " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, (void *)tdata);
      if (rc)
      {
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }
   //while(1)
   {
	   //cout<<"!!Excuting main\n";
	   //sleep(1);
   }
   pthread_exit(NULL);
}
