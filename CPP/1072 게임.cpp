// https://www.acmicpc.net/problem/1300
// silver4

#include <iostream>
using namespace std;

struct p1072
{
	int main()
	{
		int x, y;
		cin >> x >> y;

		int p0 = ((long long)y * 100) / x;
		int l = 1;
		int r = x + 1;
		while (l < r)
		{
			int m = (l + r) / 2;

			int p1 = (((long long)y + m) * 100) / ((long long)x + m);

			if (p1 == p0)
			{
				l = m + 1;
			}
			else if (p1 > p0)
			{
				r = m;
			}
		}

		if (l == x + 1)
		{
			cout << -1;
		}
		else
		{
			cout << l;
		}
	}
};