#if 0
Mutex Vs Binary Semaphore:
======================================================================================
1.Mutex means mutual exclusion
2.Mutex is used b/w  two thread or 3 of same process
3.Mutex is selfish,He own the resource ,does his work ,and release the Resource and not
  inform to other[not correct-because relesing resouce does the increment]

=======================================================================================
0.If Semaphore created more than one "shared resource" that is count or
  S value  is greater than one,is  called counting semaphopore
1.semaphore Also can achive mutual exclusion by Binary Semaphor
2.Owner Ship Is not there on resource: So ancidental case can happen   e.g Binary Semaphor
  can lead mistakes if one thread does not wait and simplay do  the increment,
  {correction if any},But in case of Mutex Ownership is there,the task
  which has occupied the resource that can only ,release or do the increment.

3.If Semaphore created with one "shared resource" that is count or S value  is one called
  binary semaphopore
  ==========================================================================================
more Detail::
//blog.feabhas.com/2009/09/mutex-vs-semaphores-%E2%80%93-part-1-semaphores/
#endif

===========================================================================================
#if 0
Modified question is - What's the difference between A mutex and a "binary" semaphore in "Linux"?

Ans: Following are the differences –
i) Scope – The scope of mutex is within a process address space which has created it and
is used for synchronization of threads. Whereas semaphore can be used across process space
and hence it can be used for interprocess synchronization.
ii) Mutex is lightweight and faster than semaphore. Futex is even faster.

iii) Mutex can be acquired by same thread successfully multiple times with condition that it
should release it same number of times. Other thread trying to acquire will block. Whereas in
case of semaphore if same process tries to acquire it again it blocks as it can be acquired only
once.
#endif


===============================================================================================
#if 0
A semaphore can be a Mutex but a Mutex can never be semaphore.This simply means that a binary
semaphore can be used as Mutex, but a Mutex can never exhibit the functionality of semaphore.
2. Both semaphores and Mutex (at least the on latest kernel) are nonÂ­recursive in nature.
3. No one owns semaphores, whereas Mutex are owned and the owner is held responsible for them.
 This is an important distinction from a debugging perspective.
4. In case the of Mutex, the thread that owns the Mutex is responsible for freeing it. However,
  in the case of semaphores, this condition is not required.
  Any other thread can signal to free the semaphore by using the s m p s ( function. e_ot)
5. A Mutex, by definition, is used to serialize access to a section of reÂ­entrant code that
  cannot be executed concurrently by more than one thread. A semaphore, by definition, restricts
  the number of simultaneous users of a shared resource up to a maximum number
6. Another difference that would matter to developers is that semaphores are systemÂ­wide and
  remain in the form of files on the filesystem, unless otherwise cleaned up. Mutex are process
   Â­wide and get cleaned up automatically when a process exits.
7. The nature of semaphores makes it possible to use them in synchronizing related and unrelated
  process, as well as between threads. Mutex can be used only in synchronizing between threads and
  at most between related processes (the pthread implementation of the latest kernel comes with a
  feature that allows Mutex to be used between related process).
8. According to the kernel
  documentation, Mutex are lighter when compared to semaphores. What this means is that a program
  with semaphore usage has a higher memory footprint when compared to a program having Mutex.

9. From a usage perspective, Mutex has simpler semantics when compared to semaphores.
#endif
#if 0



#endif
