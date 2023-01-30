// https://www.acmicpc.net/problem/5557

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5557
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		int a[100];
		long long dp[100][21]{};

		cin >> n;
		for1(i, n)
		{
			cin >> a[i];
		}
		dp[0][a[0]] = 1;

		for (int i = 1; i < n; ++i)
		{
			if (i == n - 1)
			{
				dp[i][a[i]] = dp[i - 1][a[i]];
				break;
			}

			for (int j = 0; j < 21; ++j)
			{
				if (j - a[i] >= 0)
				{
					dp[i][j] += dp[i - 1][j - a[i]];
				}
				if (j + a[i] <= 20)
				{
					dp[i][j] += dp[i - 1][j + a[i]];
				}
			}
		}

		cout << dp[n - 1][a[n - 1]];
		return 0;
	}
};