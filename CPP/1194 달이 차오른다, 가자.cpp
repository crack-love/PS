// https://www.acmicpc.net/problem/1194

#include <bits/stdc++.h>
using namespace std;

struct p1194
{
	const int dx[4] = { 0, 0, 1, -1 };
	const int dy[4] = { 1, -1, 0, 0 };

	int n, m;
	char g[50][50] = {};
	int visited[50][50][128] = {};
	int answer = -1;

	void bfs(int x, int y, int d, int k)
	{
		deque<tuple<int, int, int, int>> dq;
		dq.push_back({ x, y, d, k });
		memset(visited, -1, sizeof(visited));
		visited[x][y][k] = 0;

		while (!dq.empty())
		{
			const auto [x, y, d, k] = dq.front();
			dq.pop_front();

			const int& v = visited[x][y][k];
			if (v < d)
			{
				continue;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				char gv = g[nx][ny];
				if (gv == '#') continue;

				int nk = k;
				if (gv == '1')
				{
					// finish
					if (answer == -1) answer = d + 1;
					else answer = min(answer, d + 1);
					return;
				}
				else if ('a' <= gv && gv <= 'f')
				{
					nk |= (1 << (gv - 'a'));
				}
				else if ('A' <= gv && gv <= 'F')
				{
					int bit = (1 << (gv - 'A'));
					if (!(bit & k)) continue;
				}

				int& nv = visited[nx][ny][nk];
				if (nv == -1 || nv > d + 1)
				{
					nv = d + 1;
					dq.push_back({ nx, ny, d + 1, nk });
				}
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int begx, begy;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> g[i][j];
				if (g[i][j] == '0')
				{
					begx = i;
					begy = j;
				}
			}
		}

		bfs(begx, begy, 0, 0);
		cout << answer;
		return 0;
	}
};