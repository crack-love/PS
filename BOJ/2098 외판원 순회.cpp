// https://www.acmicpc.net/problem/2098

#include <iostream>
using namespace std;

struct p2098
{
	int n;
	int edge[16][16];
	int dp[16][1 << 16];

	int solve(int idx, int visit)
	{
		if (dp[idx][visit] != 0)
		{
			return dp[idx][visit];
		}

		if (visit == (1 << n) - 1)
		{
			if (edge[idx][0] != 0)
			{
				return edge[idx][0];
			}
			else
			{
				return -1;
			}
		}

		int minCost = -1;
		for (int i = 0; i < n; ++i)
		{
			if (edge[idx][i] == 0) continue;
			if (visit & (1 << i)) continue;

			int v = solve(i, visit | (1 << i));
			if (v == -1) continue;
			if (minCost == -1 || v + edge[idx][i] < minCost)
			{
				minCost = v + edge[idx][i];
			}
		}

		return dp[idx][visit] = minCost;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> edge[i][j];
			}
		}

		cout << solve(0, 1 << 0);
		return 0;
	}
};