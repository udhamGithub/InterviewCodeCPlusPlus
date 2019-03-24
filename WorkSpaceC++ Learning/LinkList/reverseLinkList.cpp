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

int main()
{
	LinkList *head=NULL;
	LinkList *pNode[10];
	for(int i=0;i<10;i++)
	{
		pNode[i]= new LinkList; //pNode storing LinkList type Pointer
	}
	pNode[0]->data=10;
	pNode[0]->plink=NULL;    //can we pass pointer by refrence
	insert(&head,pNode[0]);  //pointer passing by adress
				//insert(&head,pNode[0]);  pointer pass by value
	cout<<"Data" <<head->data<<endl;

	pNode[1]->data=20;
	pNode[1]->plink=NULL;
	insert(&head,pNode[1]);
	cout<<"data " << head->data<<endl;

	pNode[2]->data=30;
	pNode[2]->plink=NULL;
	insert(&head,pNode[2]);
	cout<<"Data " << head->data<<endl;

	pNode[3]->data=40;
	pNode[3]->plink=NULL;
	insert(&head,pNode[3]);
	//passing a pointer as value
	//pNode[0]-->means 1stnode adress of type LinkList passing by value

	display_List(head);
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



