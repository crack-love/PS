// https://www.acmicpc.net/problem/2239

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2239
{
	int b[9][9]{};
	int invRow[9][10]{};
	int invCol[9][10]{};
	int invBox[3][3][10]{};
	bool solve(int x, int y)
	{
		if (y >= 9)
		{
			x += 1;
			y = 0;
		}
		if (x >= 9)
		{
			return true;
		}
		if (b[x][y] != 0)
		{
			return solve(x, y + 1);
		}

		for (int k = 1; k <= 9; ++k)
		{
			if (invRow[x][k]) continue;
			if (invCol[y][k]) continue;
			if (invBox[x / 3][y / 3][k]) continue;

			invRow[x][k] = 1;
			invCol[y][k] = 1;
			invBox[x / 3][y / 3][k] = 1;
			b[x][y] = k;
			if (solve(x, y + 1))
			{
				return true;
			}
			b[x][y] = 0;
			invRow[x][k] = 0;
			invCol[y][k] = 0;
			invBox[x / 3][y / 3][k] = 0;
		}
		return false;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		for2(i, j, 9, 9)
		{
			char c;
			cin >> c;
			int v = c - '0';
			b[i][j] = v;
			invRow[i][v] = 1;
			invCol[j][v] = 1;
			invBox[i / 3][j / 3][v] = 1;
		}

		solve(0, 0);

		for2(i, j, 9, 9)
		{
			cout << b[i][j];
			if (j == 8) cout << "\n";
		}

		return 0;
	}
};