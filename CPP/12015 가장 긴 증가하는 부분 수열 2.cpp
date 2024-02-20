// https://www.acmicpc.net/problem/12015
// gold2

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct p12015
{
	int d[(int)1e6];
	int dsize = 0;

	int upperBound(int l, int r, int p)
	{
		while (l < r)
		{
			int m = (l + r) / 2;

			if (d[m] <= p)
			{
				l = m + 1;
			}
			else
			{
				r = m;
			}
		}

		return r;
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

			if (d[dsize - 1] < x)
			{
				d[dsize++] = x;
			}
			else
			{
				int r = upperBound(0, dsize, x);

				if (r > 0 && d[r - 1] == x)
				{
					continue;
				}
				d[r] = x;

				// or
				{
					/*int *r = upper_bound(d, d+ dsize, x);
					if (r > d && *(r-1) == x) continue;
					*r = x;*/
				}
				// or
				{
					//int* r = lower_bound(d, d+dsize, x);
					//*r = x;
				}
			}
		}

		cout << dsize;
		return 0;
	}
};