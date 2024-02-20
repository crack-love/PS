// https://www.acmicpc.net/problem/11060

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p11060
{
	int n;
	int a[1000];
	int dp[1000];

	int jump(int i)
	{
		if (i == 0)
		{
			return a[0] == 0 ? -1 : 0;
		}
		else if (dp[i] != 0)
		{
			return dp[i];
		}

		int ans = -1;
		for (int j = 100; j >= 1; --j)
		{
			int ni = i - j;
			if (ni >= 0 && a[ni] >= j)
			{
				int c = jump(ni);
				if (c == -1)
					continue;

				if (ans == -1)
				{
					ans = c + 1;
				}
				else
				{
					ans = min(ans, c + 1);
				}
			}
		}

		return dp[i] = ans;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for1(i, n)
		{
			cin >> a[i];
		}

		if (n == 1)
		{
			cout << "0";
		}
		else
		{
			cout << jump(n - 1);
		}

		return 0;
	}
};