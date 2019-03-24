/*
 * SemaPhoreCreateMutex.cpp


 *
 *  Created on: 24-Nov-2017
 *      Author: udham
 */
#include<iostream>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//int pthread_mutex_init(pthread_mutex_t *restrict mutex,const pthread_mutexattr_t *restrict attr);
//pthread_mutex_init(&myMutex;0);
//pthread_mutex_lock(&myMutex;);
//pthread_mutex_unlock(&myMutex;)
//pthread_mutex_destroy(&myMutex;);

using namespace std;
volatile int a;
long long int Sum=0;

void * Thread3_DrawMillionPointOnDisplay(void*)
{	//int i=0;
	while(1)
	{
		cout<<"Thread3::DrawMillionPointOnDisplay::\n";
		cout<<"sum is="<<Sum << endl;
		Sum=0;

		sleep(2);
	}
	pthread_exit(NULL);
}

void * Thread2_BusinessLogic(void*)
{
	while(1)
	{
		cout<<"Thread 2::BusinessLogic::Do Operation On Input::\n";
		for(int i=0;i< 50000000;i++)
		{
			Sum = Sum+1;
		}
		cout<<Sum<<endl;
		sleep(2);
	}
	pthread_exit(NULL);
}
void * Thread1_Keypad(void *)
{
	int X;
	while(1)
	{
		cout<<"Thread 1:Inter Enter Input ::->";
		cin >> X;
		sleep(2);
	}
	pthread_exit(NULL);
}

int main()
{
	//--------pid1-------------------------
	pthread_t pid1;
	pthread_t pid2;
	pthread_t pid3;
	//-----trying to set thread attribute-----------------------------------
	int s;
	int   policy;
	sched_param  param;

	pthread_attr_t attr;
	pthread_attr_t *attrp;

	param.__sched_priority=1;
	policy=SCHED_FIFO;
	//SCHED_FIFO
	//SCHED_RR
	//SCHED_OTHER

	pthread_create(&pid1,NULL,Thread1_Keypad,NULL);
		s = pthread_setschedparam(pid1, policy, &param);
	pthread_create(&pid2,NULL,Thread2_BusinessLogic,NULL);
		param.__sched_priority=2;
		s = pthread_setschedparam(pid2, policy, &param);
	pthread_create(&pid3,NULL,Thread3_DrawMillionPointOnDisplay,NULL);
	    param.__sched_priority=3;
		s = pthread_setschedparam(pid3, policy, &param);

	pthread_join(pid1,NULL);
	pthread_join(pid2,NULL);
}



//expected Out put:
	//-
	//-


