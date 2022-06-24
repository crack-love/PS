// https://www.acmicpc.net/problem/2231

#include <iostream>
using namespace std;

struct p2231
{
	int main()
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a = i;
			int t = i;
			while (t > 0)
			{
				a += t % 10;
				t /= 10;
			}
			if (a == n)
			{
				cout << i;
				return 0;
			}
		}
		cout << 0;
		return 0;
	}
};