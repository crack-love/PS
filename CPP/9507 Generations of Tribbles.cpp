// https://www.acmicpc.net/problem/9507

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p9507
{
	long long dp[68] = {};
	long long getdp(int i)
	{
		if (dp[i] != 0)
			return dp[i];

		return dp[i] = getdp(i - 1) + getdp(i - 2) + getdp(i - 3) + getdp(i - 4);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		dp[0] = dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			cout << getdp(n) << "\n";
		}

		return 0;
	}
};