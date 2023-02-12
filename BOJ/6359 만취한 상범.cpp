// https://www.acmicpc.net/problem/6359

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p6359
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		bool open[101][101]{};

		for (int i = 1; i <= 100; ++i)
		{
			for (int j = 1; j <= 100; ++j)
			{
				if (j % i == 0)
				{
					open[i][j] = !open[i - 1][j];
				}
				else
				{
					open[i][j] = open[i - 1][j];
				}
			}
		}

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;

			int ans = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (open[i][i])
				{
					ans += 1;
				}
			}

			cout << ans << "\n";
		}

		return 0;
	}
};