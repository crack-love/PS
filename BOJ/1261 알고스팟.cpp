// https://www.acmicpc.net/problem/

#include <iostream>
#include <queue>
using namespace std;

struct p1261
{
	int main()
	{
		char map[100][101];
		int n, m; // [1 100]
		cin >> m >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
		}

		int visit[100][100] = {};
		int cost[100][100];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cost[i][j] = -1;
			}
		}
		cost[0][0] = 0;

		struct node
		{
			int x;
			int y;
			int c;
			bool operator()(node& a, node& b)
			{
				return a.c > b.c;
			}
		};
		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		priority_queue<node, vector<node>, node> q;
		q.push({ 0, 0, 0 });

		while (true)
		{
			// get next node
			node node = {};
			while (!q.empty())
			{
				node = q.top(); q.pop();

				if (visit[node.x][node.y]) continue;
				if (cost[node.x][node.y] != node.c) continue;
				break;
			}

			if (node.x == n - 1 && node.y == m - 1)
			{
				break;
			}

			// visit node
			visit[node.x][node.y] = 1;
			for (int i = 0; i < 4; ++i)
			{
				int nx = node.x + dx[i];
				int ny = node.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visit[nx][ny]) continue;

				int nc = node.c + (map[nx][ny] == '1' ? 1 : 0);
				if (cost[nx][ny] == -1 || nc < cost[nx][ny])
				{
					cost[nx][ny] = nc;
					q.push({ nx, ny, nc });
				}
			}
		}

		cout << cost[n - 1][m - 1];
		return 0;
	}
};