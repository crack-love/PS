// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <algorithm>
using namespace std;

struct p12865
{
	int n, k;
	int w[100];
	int v[100];
	int d[100][100001]; // i, w stack

	// dir = di-1_r-wi + vi or di-1_r

	int dp(int i, int r)
	{
		if (i >= n) return 0;
		if (d[i][r] >= 0) return d[i][r];

		int d0 = 0;
		if (r - w[i] >= 0)
		{
			d0 = dp(i + 1, r - w[i]) + v[i];
		}
		int d1 = dp(i + 1, r);

		return d[i][r] = max(d0, d1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			cin >> w[i] >> v[i];
		}

		fill(&d[0][0], &d[n - 1][k + 1], -1);

		int ans = dp(0, k);
		cout << ans;

		return 0;
	}
};