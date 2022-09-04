// https://www.acmicpc.net/problem/3055

#include <bits/stdc++.h>
using namespace std;
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i) for(int j=0;j<c;++j)

struct p3055
{
	int r, c;
	int g[50][50];
	const int dx[4]{ 0, 0, 1, -1 };
	const int dy[4]{ 1, -1, 0, 0 };

	void extend()
	{
		bool noext[50][50]{};

		for2(i, j, r, c)
		{
			if (noext[i][j]) continue;

			int v = g[i][j];
			if (v == '*')
			{
				for1(k, 4)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					int nv = g[nx][ny];
					if (nv == 'D') continue;
					if (nv == 'X') continue;
					if (nv == '*') continue;

					g[nx][ny] = '*';
					noext[nx][ny] = true;
				}
			}
		}
	}

	int move()
	{
		bool nomove[50][50]{};
		bool moved = false;

		for2(i, j, r, c)
		{
			if (nomove[i][j]) continue;

			int v = g[i][j];
			if (v <= 0)
			{
				for1(k, 4)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					int nv = g[nx][ny];
					if (nv == 'X') continue;
					if (nv == '*') continue;
					if (nv == 'D') return -(v - 1);
					if (nv <= 0 && nv >= v - 1) continue;
					g[nx][ny] = v - 1;
					moved = true;
					nomove[nx][ny] = true;
				}
			}
		}
		return moved ? 0 : -1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		string line;
		cin >> r >> c;
		for (int i = 0; i < r; ++i)
		{
			cin >> line;
			for (int j = 0; j < c; ++j)
			{
				g[i][j] = line[j];
				if (g[i][j] == 'S')
				{
					g[i][j] = 0;
				}
			}
		}

		while (true)
		{
			int ans = move();
			if (ans > 0)
			{
				cout << ans;
				return 0;
			}
			else if (ans < 0)
			{
				cout << "KAKTUS";
				return 0;
			}

			extend();
		}
	}
};