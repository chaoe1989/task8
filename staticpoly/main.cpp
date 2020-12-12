#include <iostream>
using namespace std;
const int SIZE=5 ;
class Array
{

private:
public:
	int size;
	int *ps;

	Array(); //无参构函
	Array(int [],int ); //有参构函
	Array(const Array&a); //拷贝构函
	~Array(); //析构函数

	int Output(); //输出对象内容
	void Modify(); //修改数组对象的元素
	Array &operator=(Array &); //实现数组对象的赋值操作
	Array operator+(Array ); //加法操作（成员函数）

	friend Array operator-(Array ,Array ); //减法操作

};

Array::Array()
{
	this->size = SIZE;
	this->ps = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		ps[i] = i + 1;
	}
}

Array::Array(int a[],int )
{
	size = SIZE;
	ps = new int[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		ps[i] = a[i];
	}
}

Array::Array(const Array&a)
{
	this->size = a.size;
	this->ps = new int[a.size];
	for (int i = 0; i < SIZE; i++)
	{
		ps[i] = a.ps[i];
	}
}

Array::~Array()
{
	delete[]this->ps;
}

int Array::Output()
{
	cout << "enter the serial number of the member you want:";
	int temp;
	cin >> temp;
	return this->ps[temp-1];
}

void Array::Modify()
{
	cout << "enter the serial number of the member you want:";
	int temp, n;
	cin >> temp;
	cout << "which number you want to change it into:";
	cin >> n;
	this->ps[temp-1] = n;
	cout << "OK!" << endl;
}

Array &Array::operator=(Array &v)
{
	size = v.size;
	ps = new int[SIZE];
	for (int j=0;j<v.size;j++)
	{
		ps[j] = v.ps[j]; 
	}
	return *this;
}

Array Array::operator+(Array v)
{
	Array c;
	for (int k = 0; k < SIZE; k++)
	{
		c.ps[k] = ps[k] + v.ps[k];
	}
	return c;
}

Array operator-(Array a, Array b)
{
	Array d;
	for (int k = 0; k < SIZE; k++)
	{
		d.ps[k] = a.ps[k] - b.ps[k];
	}
	return d;
}
int main()
{
	int a1[5] = { 1,2,3,4,5 };
	Array a(a1,5);
	cout << "the array a is:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout<< a.ps[i]<<" ";
	}
	cout << endl;
	cout << "the size is:" << a.size << endl;

	int key=a.Output();
	cout << "the number is:" << key << endl;
	a.Modify();
	cout << "the array a is:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a.ps[i] << " ";
	}
	cout << endl;

	int a2[5] = { 2,4,6,8,10 };
	Array b(a2,8);
	cout << "the array b is:" << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << b.ps[j] << " ";
	}
	cout << endl;
	cout << "the size of b is:" << b.size << endl;

	a.operator=(b);
	Array c=a.operator+(b);	
	Array d = b-a;
	cout << "the array a is:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a.ps[i]<<" ";
	}	
	cout << endl;
	
	cout << "the array c(c=a+b) is:" << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << c.ps[j] << " " << endl;
	}

	cout << "the array d(d=a-b) is:" << endl;
	for (int j = 0; j < 5; j++)
	{
		cout << d.ps[j] << " " << endl;
	}

	system("pause");
	return 0;
}