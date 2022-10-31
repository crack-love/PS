// https://www.acmicpc.net/problem/1309

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1309
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int MOD = 9901;
		int n;
		cin >> n;
		int dp0 = 1, dp1 = 0, dp2 = 0;
		for (int i = 0; i < n; ++i)
		{
			int ndp0 = (dp0 + dp1 + dp2) % MOD;
			int ndp1 = (dp0 + dp2) % MOD;
			int ndp2 = (dp0 + dp1) % MOD;
			dp0 = ndp0;
			dp1 = ndp1;
			dp2 = ndp2;
		}
		cout << (dp0 + dp1 + dp2) % MOD;
		return 0;
	}
};