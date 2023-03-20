// https://www.acmicpc.net/problem/1743

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1743
{
	int n, m, k;
	int g[100][100]{};
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };

	int cnt = 0;
	void dfs(int x, int y)
	{
		cnt += 1;
		g[x][y] = 0;

		for1(i, 4)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			step(nx, ny, n, m);
			if (g[nx][ny] == 1)
			{
				dfs(nx, ny);
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n >> m >> k;
		for1(i, k)
		{
			int x, y;
			cin >> x >> y;
			g[x - 1][y - 1] = 1;
		}

		int answer = 0;
		for2(i, j, n, m)
		{
			if (g[i][j] == 1)
			{
				cnt = 0;
				dfs(i, j);
				answer = max(answer, cnt);
			}
		}
		cout << answer;

		return 0;
	}
};