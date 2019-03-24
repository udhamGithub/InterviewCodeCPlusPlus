/*
 * threading.cpp

 *
 *  Created on: 14-Nov-2017
 *      Author: ee205237
 */
#include<iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
#define NUM_THREADS 5

long long int sum=0;

void *thread_count(void *arg)
{
	for(int i=0;i<500000;i++)
	{
		sum=sum+ *(int*)arg;
	}
   pthread_exit(NULL);
}

int main()
{
	int rc=0;
	int i=1;
	pthread_t threads1;
	pthread_t threads2;
	rc =pthread_create(&threads1,NULL,thread_count,&i);
	pthread_join(threads1,NULL);
	cout<<"sum=="<<sum<<endl;


	int j=-1;
	rc =pthread_create(&threads2,NULL,thread_count,&j);
	pthread_join(threads2,NULL);

	cout<<" final"<<sum<<endl;
	if(rc!=0)
	{
		cout<<"error";
	}
	return 0;
}



