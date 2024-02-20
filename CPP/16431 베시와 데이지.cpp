// https://www.acmicpc.net/problem/16431

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p16431
{
	int bfs(int bx, int by, int ex, int ey, int dirsize)
	{
		const int size = 1001;
		bool visited[size][size]{};
		queue<tuple<int, int, int>> q;
		q.push({ bx,by,0 });
		visited[bx][by] = true;
		while (q.size() > 0)
		{
			auto [x, y, c] = q.front(); q.pop();

			for (int i = 0; i < dirsize; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				step(nx, ny, size, size);
				if (visited[nx][ny])continue;

				if (nx == ex && ny == ey)
				{
					return c + 1;
				}
				q.push({ nx,ny,c + 1 });
				visited[nx][ny] = true;
			}
		}

		return -1;
	}

	int main()
	{
		fastio;

		int br, bc;
		int dr, dc;
		int jr, jc;
		cin >> br >> bc;
		cin >> dr >> dc;
		cin >> jr >> jc;

		int bans = bfs(br, bc, jr, jc, 8);
		int dans = bfs(dr, dc, jr, jc, 4);
		cout << (bans == dans ? "tie" : bans < dans ? "bessie" : "daisy");

		return 0;
	}
};