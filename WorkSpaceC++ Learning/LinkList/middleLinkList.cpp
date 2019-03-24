#if 0
//user creating node and giving to insert user is doing
//Creating node and setting data is link list job logic
//Passing  pointer or Passing  pointer adress
//Insertion of a created node
//Displaying Head node data
//Freeing Allocated memory by delete one by one  or using delet[] ptr

#endif
#include<iostream>
using namespace std;
struct LinkList
{
	int data;
	struct LinkList *plink;
};
int insert(LinkList **pHead,LinkList *node);
void reverse(LinkList **node);
void display_List(LinkList *head);
void middleoflist(LinkList *head);

int main()
{
	LinkList *head=NULL;
	LinkList *pNode[10];
	for(int i=0;i<10;i++)
	{
		pNode[i]= new LinkList; //pNode storing LinkList type Pointer
	}
	for(int l=0;l<10;l++)
	{
		pNode[l]->data=l;
		pNode[l]->plink=NULL;    //can we pass pointer by refrence
		insert(&head,pNode[l]);  //pointer passing by adress
	}
//------------------------------------------------
	display_List(head);

	middleoflist(head);
//------------------------------------------------
	cout<<"Reverse the data"<<endl;
	reverse(&head);
	display_List(head);
//-------------------------------------------------
    cout<<"free the allocated memory for object LinkList"<<endl;
	//freeing memory
	for(int j=0;j<10;j++)
	{
		delete pNode[j];
	}

	// delete [] pNode; error
	cout<<"Display after LinkList object deleted"<<endl;
	display_List(head);
	cout<<"Program End"<<endl;
}

void middleoflist(LinkList *head)
{
	LinkList *fast_ptr=head;
	LinkList *slow_ptr=head;
	LinkList *PrevPtr=NULL;
    int count=0;
	while((fast_ptr!=NULL) && (fast_ptr->plink!=NULL))
	{
		fast_ptr=fast_ptr->plink->plink;

		PrevPtr=slow_ptr;

		slow_ptr=slow_ptr->plink;
	}
	if(count%2 == 0)
	{
		cout<<"Mid-Data"<<PrevPtr->data;
		cout<<"Mid-Data"<<slow_ptr->data;
	}
	else
	{
		cout<<"Mid-Data"<<slow_ptr->data;
	}
}

void display_List(LinkList *head)
{
	int i=0;
	LinkList *pCurrent= head;
	while(pCurrent != NULL)
	{
		cout<< i <<" "<<pCurrent->data<<endl;
		pCurrent =pCurrent->plink;
		i++;
	}
}

int insert(LinkList **pHead,LinkList *node)
{
	LinkList **pCurrent = pHead;
	if(((*pCurrent) == NULL) && (node!=NULL))
	{
		*pCurrent= node;
		return 0;
	}
	if( node != NULL)
	{
		node->plink = (*pCurrent)->plink;
		(*pCurrent)->plink = node;
	}
	return 0;
}						//int *ptr=10;
						//int **ptr=ptr;
						//reverse(ptr)
void reverse(LinkList** phead) //reverse(int **ptr)
{
	LinkList *pCurrent= *phead;
	LinkList *pNext=NULL;
	LinkList *pPrev=NULL;
	if(phead!=NULL)
	{
		while(pCurrent!=NULL)
		{
			pNext=pCurrent->plink;
			pCurrent->plink= pPrev;
			pPrev = pCurrent;
			pCurrent= pNext;
		}
		*phead = pPrev;
	}else
	{
		cout<<"NULL Pointer";
	}
}







