// https://www.acmicpc.net/problem/4153

#include <iostream>
using namespace std;

struct p4153
{
	int main()
	{
		while (true)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a == 0 && b == 0 && c == 0)
			{
				return 0;
			}
			if (a == 0 || b == 0 || c == 0)
			{
				cout << "wrong\n";
				continue;
			}

			if (a > c)
			{
				int t = c;
				c = a;
				a = t;
			}
			if (b > c)
			{
				int t = c;
				c = b;
				b = t;
			}

			if (a * a + b * b == c * c)
			{
				cout << "right\n";
			}
			else
			{
				cout << "wrong\n";
			}
		}
	}
};