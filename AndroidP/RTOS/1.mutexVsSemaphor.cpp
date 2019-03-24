/*
 * mutexVsSemaphor.cpp
 *
 *  Created on: 20-Nov-2017
 *      Author: udham
 */
#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
//1,2,3,4,5,6,7,8,9,10

int sum=0;

static pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;;
void *thread_1(void *)
{
	while(1)
	{
		//critical resource
		pthread_mutex_lock(&lock);
		sum=sum+1;
		pthread_mutex_unlock(&lock);
		cout<<"\nthread_1--sum=" <<sum<<endl;
		sleep(2);
	}
}
void *thread_2(void *)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		//critical resource
		sum=sum+1;
		pthread_mutex_unlock(&lock);
		cout<<"\nthread_2--sum=" <<sum<<endl;
		sleep(2);
	}
}

int main()
{
	//-------------------------------------
	pthread_t  pid1;
	pthread_t  pid2;
	//-----------------------------------------

	pthread_mutex_init(&lock,NULL);

	pthread_create(&pid1,NULL,thread_1, NULL);
	pthread_create(&pid2,NULL,thread_2, NULL);
	pthread_join(pid1 ,NULL);
	pthread_join(pid2 ,NULL);
	//----- pthread_create()------------------
	cout<<"My First Program"<<endl;
	return 0;
}

//case 1: without mutex both thread print same number--:inconsitent out put
//310,309
//thread_1--sum=355
//thread_2--sum=355


#if 0

#include <pthread.h>

	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
	 int pthread_mutex_destroy(pthread_mutex_t *mutex);

	 int pthread_mutex_lock(pthread_mutex_t *mutex);
	 int pthread_mutex_trylock(pthread_mutex_t *mutex);
	 int pthread_mutex_unlock(pthread_mutex_t *mutex);
#endif
