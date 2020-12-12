#include <iostream>
using namespace std;

class Shapes
{

public:

	virtual void display() = 0;

};

class Rectangle:public Shapes
{

public:
	Rectangle();
	Rectangle(float, float);
	~Rectangle()
	{

	}
	void display();

private:
	float l;
	float w;

};

class Point
{
public:
	Point();
	Point(float, float);
	~Point()
	{

	}
	void show();

private:
	float x, y;

};
class Circle :public Shapes
{
public:
	Circle();
	Circle(float ,float ,float );
	~Circle()
	{

	}
	void display();

private:
	float r;
	Point p;

};

Rectangle::Rectangle()
{
	l = 2;
	w = 1;
}

Rectangle::Rectangle(float ll, float ww)
{
	l = ll;
	w = ww;
}

void Rectangle::display()
{
	cout << "Rectangle:l=" << l << " w=" << w << endl;
}

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(float xx, float yy):x(xx),y(yy)
{
	x = xx;
	y = yy;
}

void Point::show()
{
	cout << "(" << x << "," << y << ")";
}

Circle::Circle() :p(0, 0)
{
	r = 1;
}

Circle::Circle(float rr, float xx,float yy) : r(rr),p(xx,yy)
{
	r = rr;
}

void Circle::display()
{
	cout << "Circle: p";
	p.show();
	cout << "r=" << r << endl;
}

void Displayshapes(Shapes *p)
{
	p->display();
}

int main()
{
	Shapes *p[2];
	Rectangle a(3,4);
	Circle b(1, 0, 0);

	Displayshapes(&a);
	Displayshapes(&b);

	system("pause");
	return 0;
}