// https://www.acmicpc.net/problem/5427

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c)
using namespace std;

struct p5427
{
	int w, h;
	char b[1001][1001]{};
	int visited[1001][1001]{};
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };

	void bfsFire(int fx, int fy)
	{
		queue<tuple<int, int, int>> q;
		q.push({ fx,fy,0 });
		visited[fx][fy] = 0;

		while (!q.empty())
		{
			auto [x, y, c] = q.front();
			q.pop();

			for1(k, 4)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				step(nx, ny, h, w) continue;
				if (b[nx][ny] != '.') continue;
				if (visited[nx][ny] > c + 1)
				{
					visited[nx][ny] = c + 1;
					q.push({ nx, ny, c + 1 });
				}
			}
		}
	}

	void bfs(int bx, int by)
	{
		// bfs each fire
		for2(i, j, h, w)
		{
			if (b[i][j] == '*')
			{
				bfsFire(i, j);
			}
		}

		queue<tuple<int, int, int>> q;
		q.push({ bx,by,0 });
		visited[bx][by] = 0;
		bool successed = false;
		while (!q.empty() && !successed)
		{
			auto [x, y, c] = q.front();
			q.pop();

			for1(k, 4)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				{
					cout << c + 1 << "\n";
					successed = true;
					break;
				}
				else
				{
					if (b[nx][ny] != '.') continue;
					if (visited[nx][ny] <= c + 1) continue;
					visited[nx][ny] = c + 1;
					q.push({ nx,ny,c + 1 });
				}
			}
		}

		if (!successed)
		{
			cout << "IMPOSSIBLE\n";
		}

	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int bx, by;
			cin >> w >> h;

			for2(i, j, h, w)
			{
				cin >> b[i][j];
				if (b[i][j] == '@')
				{
					bx = i;
					by = j;
					b[i][j] = '.';
				}
			}

			fill(&visited[0][0], &visited[1000][1001], INT_MAX);
			bfs(bx, by);
		}

		return 0;
	}
};