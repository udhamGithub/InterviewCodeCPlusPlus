/*
 * BitWiseOperation.cpp
 *
 *  Created on: 29-Nov-2017
 *      Author: ee205237
 */
//#include<iostream>

//using namespace std;
#include<stdio.h>
#include<stdlib.h>
int count_setbit(int x);
void Binary_presentation(int a);
void endinessBigLittle()
{
	int a=0x1;
	char *ptr= (char*)malloc(sizeof(int));
	*ptr= a;
	if(ptr[0] == 0 ) //lowest byte
	{
		printf("endiness=big\n");
	}
	else if(ptr[8] == 1 )
	{
		printf("endiness=little\n");
	}
}
int main()
{
	int   a=0x2, ret;
	ret = count_setbit(a);
	endinessBigLittle();
	Binary_presentation(a);

	printf("\n %x",a);
	return 0;
}
int count_setbit(int l)
{
	for(int i=0;i++;i<32)
	{

	}
	return 0;
}

void Binary_presentation(int a) //assuming that big endiness
{
	printf("\nBy shifting mask left by one in each iteration and check bit\n");
	/*31-------------------------------------0*/
	/*0000 0000 0000 0000, 0000 0000 0000 0010*/
	int mask=0x1;
	for(int i=1;i< 32;i++)
	{
		(a & mask) ? printf("1"):printf("0"); //fist bit from left
		mask = mask << 1;
	}
	int checkbit=9;
	//extracting bit and checking
	int maskValue=0x1;
	//maskValue=maskValue<<32;//Shift one by 31 goees to last value
	printf("\nSame thing by Extracting right shift of number\n");
	for(int j=0;j<31;j++)
	{
		checkbit = a & maskValue;
		printf("%d",checkbit);
		a = a >> 1; //number right shift by 1-->extraction from left
		/*31-------------------------------------0*/
		/*0000 0000 0000 0000, 0000 0000 0000 0010*/
	}

	//1.we can do it in two way store data in 32 size array at from 32 location and completion print it
	//2.first right shift  mask by 32 or take mask 0x8000000
	//			-->now again left shift the mask and check bit by bit
	     int checkbit2=9;
		//extracting bit and checking
		int maskValue2=0x80000000;
		//maskValue=maskValue<<32;//Shift one by 31 goees to last value
		printf("\nCorrect format.\n");
		for(int k=0;k<32;k++)
		{
			checkbit2 = a & maskValue2;
			printf("%d",checkbit2);
			//a = a >> 1; //number right shift by 1-->extraction from left
			if(k==0)
			{
				maskValue2=0x40000000;
			}
			else
			{
				maskValue2= maskValue2 >> 1; //yielding negative  so it is not correct
			}

			/*31-------------------------------------0*/
			/*0000 0000 0000 0000, 0000 0000 0000 0010*/
		}

}



