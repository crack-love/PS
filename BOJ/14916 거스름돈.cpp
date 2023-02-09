// https://www.acmicpc.net/problem/14916

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p14916
{
	int dp[100001];
	int mincnt(int x)
	{
		if (dp[x] != 0) return dp[x];

		int v0 = mincnt(x - 2);
		int v1 = mincnt(x - 5);
		if (v0 == -1 && v1 == -1) return dp[x] = -1;
		if (v1 == -1) return dp[x] = v0 + 1;
		if (v0 == -1) return dp[x] = v1 + 1;
		return dp[x] = min(v0 + 1, v1 + 1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		if (n == 0)
		{
			cout << 0;
			return 0;
		}

		dp[0] = -1;
		dp[1] = -1;
		dp[2] = 1;
		dp[3] = -1;
		dp[4] = 2;
		dp[5] = 1;
		cout << mincnt(n);

		return 0;
	}
};