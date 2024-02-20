// https://www.acmicpc.net/problem/4179

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p4179
{
	int r, c;
	char b[1000][1000];
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };
	int visited[1000][1000]{};
	int answer = -1;

	void bfs(int i, int j, bool fire)
	{
		deque<tuple<int, int, int>> q;
		q.push_back({ i, j, 0 });
		visited[i][j] = 0;
		while (!q.empty())
		{
			auto [x, y, cnt] = q.front();
			q.pop_front();

			if (!fire)
			{
				if (x == 0 || x == r - 1 || y == 0 || y == c - 1)
				{
					answer = cnt + 1;
					return;
				}
			}

			for1(k, 4)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				step(nx, ny, r, c);
				if (visited[nx][ny] <= cnt + 1) continue;
				if (b[nx][ny] == '#') continue;
				visited[nx][ny] = cnt + 1;
				q.push_back({ nx, ny, cnt + 1 });
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int bx, by;
		cin >> r >> c;
		for2(i, j, r, c)
		{
			cin >> b[i][j];
			if (b[i][j] == 'J')
			{
				bx = i;
				by = j;
			}
		}

		fill(&visited[0][0], &visited[r - 1][c], INT_MAX);

		for2(i, j, r, c)
		{
			if (b[i][j] == 'F')
			{
				bfs(i, j, true);
			}
		}

		bfs(bx, by, false);

		if (answer == -1)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			cout << answer;
		}

		return 0;
	}
};