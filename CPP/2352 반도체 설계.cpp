// https://www.acmicpc.net/problem/2352
// gold2

#include <iostream>
using namespace std;

struct p2352
{
	int d[40000];

	int lowerBound(int l, int r, int v)
	{
		while (l < r)
		{
			int m = (l + r) / 2;

			if (d[m] < v)
			{
				l = m + 1;
			}
			else
			{
				r = m;
			}
		}
		return l;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int dsize = 0;
		int n;
		cin >> n;
		cin >> d[dsize++];
		for (int i = 2; i <= n; ++i)
		{
			int x;
			cin >> x;

			if (x > d[dsize - 1])
			{
				d[dsize++] = x;
			}
			else
			{
				int lb = lowerBound(0, dsize, x);
				d[lb] = x;
			}
		}

		cout << dsize;
		return 0;
	}
};