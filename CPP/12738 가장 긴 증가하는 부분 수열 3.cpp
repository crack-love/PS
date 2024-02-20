// https://www.acmicpc.net/problem/12738
// gold2

#include <iostream>
using namespace std;

struct p12738
{
	int d[(int)1e6];
	int dsize = 0;

	int lowerBound(int l, int r, int p)
	{
		while (l < r)
		{
			int m = (l + r) / 2;

			if (d[m] < p)
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

		int n; // [1 1e6]
		cin >> n;
		cin >> d[dsize++];
		for (int i = 1; i < n; ++i)
		{
			int x;
			cin >> x;

			if (x > d[dsize - 1])
			{
				d[dsize++] = x;
				continue;
			}

			int lb = lowerBound(0, dsize, x);
			d[lb] = x < d[lb] ? x : d[lb];
		}

		cout << dsize;
		return 0;
	}
};