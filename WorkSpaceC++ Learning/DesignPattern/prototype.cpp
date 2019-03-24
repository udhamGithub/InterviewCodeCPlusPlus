#if 0
-prototype design pattern
-When Should  use
-can we use copy constructor  for prototyp
-When object creation is costly ,to much time
-Cretion ,Composion,and presentation
-Cretion of object and its state are same.
-
-Eg.Chase game example
--------------------------------------------
client
registry
prototyp
---------------------------------
I can take the example of factory design pattern,And escape the creating objects each time,
store creatd object at reposity,while factory creation.When ever use need ,provide the interface
	=to get clone object
	=Copy constructor object.
		=Deep copy
		=Shallow copy
------------------------------------------------------------------------------------
What is the use to provide a function body for pure virtual functions, if they are not going get
called at all?
-------------------------------------------------------------------------------------------------
https://sourcemaking.com/design_patterns/prototype/cpp/1
	-In this link  object is every time created ,in clonining, it is not copying
https://www.youtube.com/watch?v=KBkkEKNlE6I&t=1s
	--In this link  object is one time created ,in clonining, it is copying the object refrence
	,which is already created
#endif


#include<iostream>
using namespace std;

enum TYPE
{
	SQUARE,
	CIRCLE,
	RECTANGLE,
	SCROLLER
};

class Shape
{
	int lenth;;
public:
	virtual void draw()= 0;
};

void Shape::draw()
{
	cout<<"Base class constructor called";
}

class square: public Shape
{
public:
	virtual void draw()
	{
		cout<<"Square"<<endl;
	}

};
class Circle: public Shape
{
public:
	virtual void draw()
	{
		cout<<"circle"<<endl;
	}
};

class Rectangle: public Shape
{
public:
	virtual void draw()
	{
		cout<<"circle"<<endl;
	}
};

void InitFactory( TYPE type)
{


}

//---------------------------------------

class clientDrawing
{
	Shape *ptr;
public:
	void drawImage()
	{
		cout<<"client class";
	}
};

//------------------------------------
int main(int argc,char ** argv)
{
	cout<<"protype Method"<<endl;
	return  0;
}


