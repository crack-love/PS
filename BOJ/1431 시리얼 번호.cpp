// https://www.acmicpc.net/problem/1431

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1431
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string a[50];
		int n;
		cin >> n;
		for1(i, n)
		{
			cin >> a[i];
		}

		sort(a, a + n, [](string& x, string& y) -> bool
			{
				if (x.size() == y.size())
				{
					int asum = 0;
					int bsum = 0;
					for1(i, x.size())
					{
						if ('0' <= x[i] && x[i] <= '9')
						{
							asum += x[i] - '0';
						}
						if ('0' <= y[i] && y[i] <= '9')
						{
							bsum += y[i] - '0';
						}
					}

					if (asum == bsum)
					{
						return x < y;
					}
					else
					{
						return asum < bsum;
					}
				}
				else
				{
					return x.size() < y.size();
				}
			});

		for1(i, n)
		{
			cout << a[i] << "\n";
		}

		return 0;
	}
};