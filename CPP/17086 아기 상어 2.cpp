// https://www.acmicpc.net/problem/17086

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p17086
{
	int n, m;
	int g[50][50];
	int bfs(int x, int y)
	{
		bool visited[50][50]{};
		queue<tuple<int, int, int>> q;
		q.push({ x,y,0 });
		visited[x][y] = true;
		while (q.size() > 0)
		{
			auto [cx, cy, d] = q.front();
			q.pop();

			if (g[cx][cy] == 1)
			{
				return d;
			}

			for1(i, 8)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				step(nx, ny, n, m);
				if (visited[nx][ny]) continue;
				visited[nx][ny] = true;
				q.push({ nx,ny,d + 1 });
			}
		}
		return 0;
	}

	int main()
	{
		fastio;

		cin >> n >> m;
		for2(i, j, n, m)
		{
			cin >> g[i][j];
		}

		int ans = 0;
		for2(i, j, n, m)
		{
			ans = max(ans, bfs(i, j));
		}
		cout << ans;
		return 0;
	}
};