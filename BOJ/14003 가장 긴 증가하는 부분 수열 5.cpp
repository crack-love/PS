// https://www.acmicpc.net/problem/14003
// platinum5

#include <iostream>
#include <vector>
using namespace std;

struct p14003
{
	int lowerBound(int l, int r, int p, int d[])
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
		cout.tie(0);

		const int MAX = 1e6;
		int a[MAX];
		int d[MAX];
		int s[MAX];
		int dsize = 0;
		int n; // [1 1e6]

		cin >> n;
		cin >> a[0];
		d[dsize++] = a[0];
		s[0] = 1;

		for (int i = 1; i < n; ++i)
		{
			cin >> a[i];

			if (a[i] > d[dsize - 1])
			{
				d[dsize++] = a[i];
				s[i] = dsize;
				continue;
			}

			int lb = lowerBound(0, dsize, a[i], d);
			if (a[i] < d[lb])
			{
				d[lb] = a[i];
				s[i] = lb + 1;
			}
		}

		int tdsize = dsize;
		vector<int> ans(dsize, 0);
		for (int i = n - 1; i >= 0; --i)
		{
			if (s[i] == tdsize)
			{
				ans[tdsize - 1] = a[i];

				if (--tdsize == 0)
				{
					break;
				}
			}
		}

		cout << dsize << "\n";
		for (int i = 0; i < dsize; ++i)
		{
			cout << ans[i] << " ";
		}
		return 0;
	}
};