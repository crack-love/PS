// https://www.acmicpc.net/problem/2564

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2564
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		const int BLOCKED = 2;
		const int EMPTY = 0;
		const int SPOT = 1;
		int g[101][101]{};
		int w, h;
		cin >> w >> h;
		w += 1;
		h += 1;
		for2(i, j, h, w)
			g[i][j] = BLOCKED;
		for1(i, h)
			g[i][0] = g[i][w - 1] = EMPTY;
		for1(i, w)
			g[0][i] = g[h - 1][i] = EMPTY;

		int n;
		cin >> n;
		int sx, sy;
		for1(i, n + 1)
		{
			int a, b;
			cin >> a >> b;
			int x, y;
			if (a == 1) //north
			{
				x = 0;
				y = b;
			}
			else if (a == 2) // south
			{
				x = h - 1;
				y = b;
			}
			else if (a == 3) // west
			{
				x = b;
				y = 0;
			}
			else if (a == 4) // east
			{
				x = b;
				y = w - 1;
			}

			if (i == n)
			{
				sx = x;
				sy = y;
			}
			else
			{
				g[x][y] = SPOT;
			}
		}

		queue<tuple<int, int, int>> q;
		q.push({ sx,sy, 0 });
		g[sx][sy] = BLOCKED;

		int found = 0;
		int ans = 0;
		while (q.size() > 0)
		{
			auto [x, y, d] = q.front();
			q.pop();

			if (found == n)
			{
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				step(nx, ny, h, w);
				if (g[nx][ny] == BLOCKED) continue;
				if (g[nx][ny] == SPOT)
				{
					found += 1;
					ans += d + 1;
				}
				g[nx][ny] = BLOCKED;
				q.push({ nx,ny,d + 1 });
			}
		}

		cout << ans;
		return 0;
	}
};