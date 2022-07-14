// https://www.acmicpc.net/problem/2665

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

struct p2665_dijk
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		char map[50][51];
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
		}

		int cost[50][50] = {};
		fill(&cost[0][0], &cost[49][50], -1);
		cost[0][0] = map[0][0] == '1' ? 0 : 1;

		priority_queue<tuple<int, int, int>> q;
		q.push({ -cost[0][0], 0, 0 });

		while (!q.empty())
		{
			int x, y, c;
			tie(c, x, y) = q.top();
			c *= -1;
			q.pop();
			if (cost[x][y] != c) continue;

			if (x == n - 1 && y == n - 1)
			{
				cout << c;
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

				int nc = c + (map[nx][ny] == '1' ? 0 : 1);
				if (cost[nx][ny] == -1 || nc < cost[nx][ny])
				{
					q.push({ -nc, nx, ny });
					cost[nx][ny] = nc;
				}
			}
		}

		return 0;
	}
};