// https://www.acmicpc.net/problem/1913

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue

using namespace std;

struct p1913
{
	const int dx[4] = { -1,0,1,0 };
	const int dy[4] = { 0,1,0,-1 };
	int n;
	int a[999][999];
	int target;
	int ansx, ansy;
	void fillSquare(int x, int y, int dir, int i, int j, int level, int v)
	{
		a[x][y] = v;

		if (v == target)
		{
			ansx = x;
			ansy = y;
		}

		if (v == n * n)
			return;

		if (j >= level)
		{
			j = 0;
			i += 1;
			dir = (dir + 1) % 4;
		}
		if (i >= 2)
		{
			i = 0;
			level += 1;
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		fillSquare(nx, ny, dir, i, j + 1, level, v + 1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n >> target;

		fillSquare(n / 2, n / 2, 3, 2, 0, 0, 1);

		for2(i, j, n, n)
		{
			cout << a[i][j];

			if (j == n - 1)
				cout << "\n";
			else
				cout << " ";
		}

		cout << ansx + 1 << " " << ansy + 1;

		return 0;
	}
};