#if 0
1.In This methos client is not decoupled with  base class  as client is taking pointer
of  base classs and then getting the object at run time
			shape *ptr1 = getObjectFromFactory(CIRCLE);
			ptr1->draw();
2.How to decoupled completely client from  this
#endif

#include<iostream>
#include <vector>
using namespace std;
class shape
{
public:
	//shape(){cout<<"shape:Base constructure"<<endl;}
	virtual void draw(void)
	{
		{cout<<"shape::draw"<<endl;}
	}
};

class circle: public shape
{
public:
	//circle(){cout<<"circle constructure"<<endl;}
	virtual void draw(void)
	{cout<<"circle::draw"<<endl;}
};


class rectangle: public shape
{
public:
	//rectangle()
	//{cout<<"rectangle constructor"<<endl;}
	virtual void draw(void)
	{ 	cout<<"rectangle:: draw"<<endl; }
};
class square: public shape
{
	virtual void draw(void)
		{ 	cout<<"square:: draw"<<endl; }
};

// Factory is from  library==================================
enum shapetype
{
	CIRCLE,
	RECTANGLE,
	SQUARE,
};

shape * getObjectFromFactory(shapetype ishapetype)
{
	shape *basePtr = NULL; //once goes out of scope basPter get deleted
	if(ishapetype ==  CIRCLE )
	{
		basePtr= new circle;
	}
	else if(ishapetype ==  RECTANGLE )
	{
		basePtr = new rectangle;
	}
	else if(ishapetype ==  SQUARE )
	{
		basePtr = new square;
	}
	else
	{
		cout<<"Object is not in  Factory"<<endl;
	}
	return basePtr;
}

int main()
{
	//client code
	shape *ptr1 = getObjectFromFactory(CIRCLE);
	ptr1->draw();

	shape *ptr2 = getObjectFromFactory(RECTANGLE);
	ptr2->draw();
	return 0;
};



