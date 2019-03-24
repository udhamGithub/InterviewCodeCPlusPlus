/*
 * joining_thread.cpp

 *
 *  Created on: 15-Nov-2017
 *      Author: udham
 */

#if 0
The pthread_join() subroutine blocks the calling thread until the
specified threadid thread terminates. When a thread is created,
one of its attributes defines whether it is joinable or detached.
Only threads that are created as joinable can be joined.
If a thread is created as detached, it can never be joined.
#endif


#include<iostream>
#include<pthread.h>
//#include<cstdlib>
#include<unistd.h>
using namespace std;

struct data
{
	int a;
	char *msg;
};
void * subroutine(void * msg)
{
	struct data *r_data;
	r_data=(struct data *)msg;
	cout<<"\nthreadid:"<< r_data->a;
	cout<<"\ndata receieved:"<< r_data->msg;
	sleep(1);
	pthread_exit(NULL);
}
int main()
{
	int rc;
	int i;
	pthread_t  thread[5];
	pthread_attr_t pt_atr;
	struct data msg_t[5];

	void *status=0;
	rc=pthread_attr_init(&pt_atr);
	rc=pthread_attr_setdetachstate(&pt_atr,PTHREAD_CREATE_JOINABLE);

	for(i=0;i<5 ;i++)
	{
		msg_t[i].a= i;
		msg_t[i].msg= "this is message";
		rc =pthread_create(&thread[i],NULL,subroutine,(void*)msg_t);
	}

	pthread_attr_destroy(&pt_atr);
	for(i=0 ; i<5 ; i++)
	{
		pthread_join(thread[i],&status) ;
		 cout << "Main: completed thread id :" << i ;
		 cout << "  exiting with status :" << status << endl;
	}
	 cout << "Main: program exiting." << endl;
	 pthread_exit(NULL);
}
