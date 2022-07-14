// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct p13549_dijik
{
	typedef pair<int, int> pi;

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, k;
		cin >> n >> k;

		const int MAX = 200001;
		bool visit[MAX] = {};
		int cost[MAX] = {};
		priority_queue<pi, vector<pi>, greater<pi>> q;

		for (int i = 0; i < MAX; ++i)
		{
			cost[i] = MAX;
		}
		q.push(make_pair(0, n));
		cost[n] = 0;

		while (!q.empty())
		{
			int x = q.top().second;
			int xc = q.top().first; q.pop();
			if (cost[x] != xc) continue;

			if (x == k)
			{
				cout << xc;
			}

			visit[x] = true;

			if (x * 2 < MAX && !visit[x * 2] && xc < cost[x * 2])
			{
				cost[x * 2] = xc;
				q.push({ xc, x * 2 });
			}

			if (x - 1 >= 0 && !visit[x - 1] && xc + 1 < cost[x - 1])
			{
				cost[x - 1] = xc + 1;
				q.push({ xc + 1, x - 1 });
			}

			if (x + 1 < MAX && !visit[x + 1] && xc + 1 < cost[x + 1])
			{
				cost[x + 1] = xc + 1;
				q.push({ xc + 1, x + 1 });
			}
		}

		return 0;
	}
};