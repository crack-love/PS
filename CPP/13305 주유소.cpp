// https://www.acmicpc.net/problem/13305

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p13305
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int dist[(int)1e5];
		int cost[(int)1e5];
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> dist[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> cost[i];
		}

		long long costSum = 0;
		int minCost = (int)1e9 + 1;
		for (int i = 0; i < n - 1; ++i)
		{
			minCost = min(cost[i], minCost);
			costSum += (long long)dist[i] * minCost;
		}

		cout << costSum;

		return 0;
	}
};