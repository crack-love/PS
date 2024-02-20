// https://www.acmicpc.net/problem/23288

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p23288
{
	int n, m, k;
	int g[20][20];
	int visited[20][20];
	int dfs(int x, int y)
	{
		if (visited[x][y])
			return 0;
		visited[x][y] = 1;

		int c = 1;
		for1(i, 4)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			step(nx, ny, n, m);
			if (g[nx][ny] == g[x][y])
			{
				c += dfs(nx, ny);
			}
		}
		return c;
	}

	int main()
	{
		fastio;

		cin >> n >> m >> k;
		for2(i, j, n, m)
		{
			cin >> g[i][j];
		}

		int gscore[20][20]{};
		for2(i, j, n, m)
		{
			memset(visited, 0, sizeof(visited));
			gscore[i][j] = dfs(i, j);
		}

		deque<int> rq = { 4,1,3,6 };
		deque<int> cq = { 2,1,5,6 };
		int dir = 0;
		const int dx[] = { 0,1,0,-1 };
		const int dy[] = { 1,0,-1,0 };
		auto nextque = [&rq, &cq](int dir)
		{
			switch (dir)
			{
			case 0:
				rq.push_front(rq.back());
				rq.pop_back();
				break;
			case 1:
				cq.push_front(cq.back());
				cq.pop_back();
				break;
			case 2:
				rq.push_back(rq.front());
				rq.pop_front();
				break;
			case 3:
				cq.push_back(cq.front());
				cq.pop_front();
				break;
			}
			if (dir % 2 == 0)
			{
				cq[1] = rq[1];
				cq[3] = rq[3];
			}
			else
			{
				rq[1] = cq[1];
				rq[3] = cq[3];
			}
		};

		int score = 0;
		int x = 0, y = 0;
		while (k--)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				dir = (dir + 2) % 4;
				k += 1;
				continue;
			}
			x = nx;
			y = ny;
			nextque(dir);

			score += gscore[x][y] * g[x][y];

			int a = rq[3];
			int b = g[x][y];
			if (a > b)
			{
				dir = (dir + 1) % 4;
			}
			else if (a < b)
			{
				dir = (dir + 3) % 4;
			}
		}

		cout << score;
		return 0;
	}
};