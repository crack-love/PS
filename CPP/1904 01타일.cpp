// https://www.acmicpc.net/problem/1904

#include <bits/stdc++.h>
using namespace std;

struct p1904
{
	int dp[(int)1e6 + 1] = {};

	int solve(int i)
	{
		if (i == 1) return 1;
		if (i == 2) return 2;
		if (dp[i] != -1) return dp[i];
		return dp[i] = (solve(i - 2) + solve(i - 1)) % 15746;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << solve(n);

		return 0;
	}
};