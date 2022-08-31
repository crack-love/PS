#include <iostream>
using namespace std;

class A
{
public:
	virtual void f1()
	{
		cout << "AF1\n";
	}

	void f2()
	{
		cout << "AF2\n";
	}
};

class D : public A
{
public:
	virtual void f1()
	{
		cout << "DF1\n";
	}

	void f2()
	{
		cout << "DF2\n";
	}
};

int* loc()
{
	static int a = 0;
	cout << a << "\n";
	return &a;
}

int main1()
{
	int* a = new int;
	*a = 2;
	delete a;

	*a = 1;
	return 1;
}