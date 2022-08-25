// https://www.acmicpc.net/problem/2163

#include <bits/stdc++.h>
using namespace std;

struct p2163
{
	int32_t dp[301][301];

	int cut(int n, int m)
	{
		if (dp[n][m] != 0) return dp[n][m];
		if (n == 1 && m == 1) return 0;
		if (n > m) swap(n, m);
		if (n == 1) swap(n, m);

		int cnt = 1;
		if (n % 2 == 0)
		{
			cnt += cut(n / 2, m) * 2;
		}
		else
		{
			cnt += cut(n / 2, m) + cut(n / 2 + 1, m);
		}

		return dp[n][m] = cnt;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, m;
		cin >> n >> m;
		cout << cut(n, m);
		return 0;
	}
};