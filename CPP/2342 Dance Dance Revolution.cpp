// https://www.acmicpc.net/problem/2342
// gold3

#include <iostream>
#include <vector>
using namespace std;

#define min(x,y) (x < y ? x : y)

struct p2342
{
	int n = 0;
	int o[100001] = {};
	int d[100001][5][5] = {};
	int cost[5][5] = {};

	void initCost()
	{
		for (int i = 0; i < 4; ++i)
		{
			// center
			cost[4][i] = 2;

			// self
			cost[i][i] = 1;

			// near
			cost[i][(i + 1) % 4] = 3;
			cost[i][(i - 1 + 4) % 4] = 3;

			// other side
			cost[i][(i + 2) % 4] = 4;
			cost[i][(i - 2 + 4) % 4] = 4;
		}
	}

	// dijk = min di..j..k+1 + cost
	int dp(int k, int i, int j)
	{
		if (k == n) return 0;
		if (d[k][i][j] != 0) return d[k][i][j];

		int t = o[k + 1];
		int r0 = dp(k + 1, t, j) + cost[i][t];
		int r1 = dp(k + 1, i, t) + cost[j][t];
		return d[k][i][j] = min(r0, r1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		while (true)
		{
			int a;
			cin >> a;
			if (a == 0) break;
			else o[++n] = a - 1;
		}

		initCost();

		int ans = dp(0,4,4);
		cout << ans << "\n";

		return 0;
	}
};