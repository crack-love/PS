// https://www.acmicpc.net/problem/1261

#include <iostream>
#include <queue>
using namespace std;

struct p1261_bfs
{
	int main()
	{
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
		char map[100][101];
		int visit[100][100] = {};

		int n, m; // [1 100]
		cin >> m >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
		}

		q.push({0, 0, 0});
		visit[0][0] = 1;

		while (!q.empty())
		{
			int x = q.top().x;
			int y = q.top().y;
			int c = q.top().c; q.pop();

			if (x == n - 1 && y == m - 1)
			{
				cout << c;
				return 0;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visit[nx][ny]) continue;
				
				int nc = c + (map[nx][ny] == '1' ? 1 : 0);
				q.push({nx, ny, nc});
				visit[nx][ny] = 1;
			}
		}

		return 0;
	}
};