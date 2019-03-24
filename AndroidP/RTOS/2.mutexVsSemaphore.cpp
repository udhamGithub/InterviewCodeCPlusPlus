
#include<iostream>
#include<pthread.h>
#include<unistd.h>
//--------------------------------
#include <semaphore.h>
#include <fcntl.h> //for type

#include <sys/time.h>

using namespace std;
//1,2,3,4,5,6,7,8,9,10
int     sum=0;
sem_t * sem_id;
void *thread_1(void *)
{
	while(1)
	{
		cout<<"\nthread_1:Waiting for signal::";
		sem_wait(sem_id);
		sum=sum+1;
		cout<<"\nthread_1  Added::sum::=" <<sum<<endl;
		sem_post(sem_id);
		cout<<"\nThread1 Posted signal going to sleep::"<<endl;
		sleep(4);
		if(sum==20)
		{
			pthread_exit(NULL);
		}
	}
}
void *thread_2(void *)
{
	int ret=-1;
	while(1)
	{
	 	//critical resource
		cout<<"\nthread_2:Waiting for signal::2::";
		ret =sem_wait(sem_id);
		sum=sum+1;		//pthread_mutex_unlock(&lock);
		cout<<"\nthread_2 Added sum::2::" <<sum<<endl;
		sem_post(sem_id);
		cout<<"Thread2 Posted signal going to sleep::2::"<<endl;

		sleep(3);
		if(sum==20)
		{
			pthread_exit(NULL);
		}
	}
}
void *thread_3(void *)
{
	while(1)
	{
	 	//critical resource
		cout<<"\nthread_3:Waiting for signal::";
		sem_wait(sem_id);

		sum=sum+1;		//pthread_mutex_unlock(&lock);
		cout<<"\nthread_3 Added sum::::" <<sum<<endl;
		sem_post(sem_id);
		cout<<"Thread3 Posted signal going to sleep::2::"<<endl;

		sleep(3);
		if(sum==20)
		{
			pthread_exit(NULL);
		}
	}
}
int main()
{
	unsigned long int sec= time(NULL);
	cout<<"AppStartTime::"<<sec<<endl;
	//-------------------------------------
	pthread_t  pid1;
	pthread_t  pid2;
	pthread_t  pid3;
	//-----------------------------------------

	//sem_id=sem_open("Sem_1",O_CREAT,NULL);sem_open("/sem1", O_CREAT | O_EXCL, 0644, 0)
	//sem_id=sem_open("/Sem1", O_CREAT | O_EXCL, 0644, 0);
	sem_id=sem_open("/Sem1", O_CREAT,NULL,1);
	if(sem_id == SEM_FAILED)
	{
         return 0;
	}
	pthread_create(&pid1,NULL,thread_1, NULL);
	pthread_create(&pid2,NULL,thread_2, NULL);
	pthread_create(&pid3,NULL,thread_3, NULL);

	pthread_join(pid1 ,NULL);
	pthread_join(pid2 ,NULL);

	sem_close(sem_id);
	sem_unlink("/Sem1");
	//----- pthread_create()------------------
	cout<<"My First Program"<<endl;
	sec= time(NULL);
	cout<<"AppEndTime::"<<sec<<endl;
	return 0;
}
#if 0
//thread creation
//thread synchronisation using semaphore
//how much time took by program to rich 100 count in case of semaphore and Mutex
//what is the priority of each thread here?is both priority has same by default?so what is the role of priority
//Thread priority setting Attribute Setting
//can third thread can create and he can wait?
//which thread exit first after reaching 100,will parent thread wait to finish second thread to
//Supposing All thread are same priority:
			//Make One Thread to  do huge operation and 1 second sleep
			//Other thread if get resume ,they should get failed to wait,as semphore count is not available
#endif

#if 0
on pthread:
https://www.youtube.com/watch?v=RPtsz0Psd2M&t=316s
//------------------

http://man7.org/linux/man-pages/man7/sem_overview.7.html
http://man7.org/linux/man-pages/man3/sem_init.3.html
http://pubs.opengroup.org/onlinepubs/009695399/functions/sem_open.html

Two processes can operate on the same named semaphore by passing the same name to
sem_open(3).
--------------------------------------------------------------------------------
sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);

0.
1.The value argument specifies the  initial value for the new semaphore
2.if O_CREAT is specified, and a  semaphore with the given name already exists,
then mode and value are ignored.
=================================================================================
Named semaphores
Two processes can operate on the same named  semaphore by passing the same name to
sem_open(3).The sem_open(3) function creates a new named semaphore or opens an
existing named semaphore.
---------------------------------------------------------------------------------
sem_open(3)
sem_unlink(3).
---------------------------------------------------------------------------------
sem_post(3)
sem_wait(3).
sem_close(3)
==================================================================================
Unnamed semaphores (memory-based semaphores)
==============================================================================
1.An unnamed semaphore does not have a name.Instead the semaphore is placed in a
region of memory that is shared between.
	a.multiple threads (a thread-shared semaphore)
	b.or  processes (a process-shared semaphore).

A thread-shared semaphore is placed in an area of memory shared between the threads of a process,
for  example, a global variable.

A process-shared semaphore must be placed in a shared memory egion
	e.g., a System V shared memory segment created  using shmget(2),or a POSIX shared memory object
	built created using shm_open(3)).
------------------------------------------------------------------------------------
Before being used, an unnamed semaphore must be initialized using
		-shm_open(3)),shmget(2)
		-sem_init(3).
		-sem_post(3)
		-sem_wait(3).
		-sem_destroy()
------------------------------------------------------------------------------------
Process Threads(1,2,3) can use unamed semaphore? Yes,
Process(1,2,3) can use named Semaphore? Yes/No-yes

Note: two ways memory can shared  1.System V shared(old) or 2.POSIX shared memory(latest)
#endif
#if 0
What is system call?
See This How Fork is being use?
https://stackoverflow.com/questions/2294584/how-can-i-get-multiple-calls-to-sem-open-working-in-c
#endif
