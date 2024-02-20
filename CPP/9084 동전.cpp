// https://www.acmicpc.net/problem/9084

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p9084
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n, m;
			int a[20];
			int dp[10001]{};

			cin >> n;
			for1(i, n)
			{
				cin >> a[i];
			}
			cin >> m;

			for (int i = 0; i < n; ++i)
			{
				dp[a[i]] += 1;

				for (int j = a[i]; j <= m; ++j)
				{
					dp[j] += dp[j - a[i]];
				}
			}

			cout << dp[m] << "\n";
		}

		return 0;
	}
};