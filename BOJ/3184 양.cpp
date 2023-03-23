// https://www.acmicpc.net/problem/3184

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p3184
{
	int r, c;
	char g[250][250];
	int wc, sc;
	void dfs(int x, int y)
	{
		if (g[x][y] == 'o')
		{
			sc += 1;
		}
		else if (g[x][y] == 'v')
		{
			wc += 1;
		}
		g[x][y] = '@';

		for1(i, 4)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			step(nx, ny, r, c);
			if (g[nx][ny] != '#' && g[nx][ny] != '@')
			{
				dfs(nx, ny);
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> r >> c;
		for2(i, j, r, c)
		{
			cin >> g[i][j];
		}

		int ansWc = 0;
		int ansSc = 0;
		for2(i, j, r, c)
		{
			if (g[i][j] == 'o' || g[i][j] == 'v')
			{
				wc = 0, sc = 0;
				dfs(i, j);
				if (sc > wc)
				{
					ansSc += sc;
				}
				else
				{
					ansWc += wc;
				}
			}
		}
		cout << ansSc << " " << ansWc;

		return 0;
	}
};