// https://www.acmicpc.net/problem/1029
// gold1

#include <iostream>
#include <algorithm>
using namespace std;

int p1029()
{
	// graph with weight
	// search highest count node route

	int n; // [2 15]
	char g[15][16] = {};
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> g[i];
		for (int j = 0; j < n; ++j) g[i][j] -= '0';
	}

	int answer = 1;

	// minCost to i with visitmask(2^16-1)
	int mc[15][65535];
	fill(&mc[0][0], &mc[14][65535], 10);

	// visit next from idx
	auto dfs = [&g, &answer, &mc, n](int idx, int cnt, int cost, int32_t visit, auto& self) -> void
	{
		if (mc[idx][visit] <= cost) return;
		mc[idx][visit] = cost;

		if (cnt > answer)
		{
			answer = cnt;
		}

		// move to next
		for (int i = 0; i < n; ++i)
		{
			if ((visit & (1<<i)) > 0) continue;
			if (g[idx][i] < cost) continue;

			self(i, cnt + 1, g[idx][i], visit | (1<<i), self);
		}
	};

	dfs(0, 1, 0, 1, dfs);

	cout << answer << "\n";
	return 0;
}