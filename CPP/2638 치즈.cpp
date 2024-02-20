// https://www.acmicpc.net/problem/2638

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p2638
{
	int n, m;
	int a[100][100]{};
	int outside[100][100]{};

	void dfsSetOutside(int x, int y)
	{
		if (outside[x][y])
			return;

		outside[x][y] = true;

		for1(k, 4)
		{
			int nx = x + dd[0][k];
			int ny = y + dd[1][k];
			step(nx, ny, n, m);

			if (!outside[nx][ny] && a[nx][ny] == 0)
			{
				dfsSetOutside(nx, ny);
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n >> m;
		for2(i, j, n, m)
		{
			cin >> a[i][j];
		}

		int t = 0;
		while (true)
		{
			// set outside
			memset(outside, 0, sizeof(outside));
			for1(i, n)
			{
				dfsSetOutside(i, 0);
				dfsSetOutside(i, m - 1);
			}
			for1(i, m)
			{
				dfsSetOutside(0, i);
				dfsSetOutside(n - 1, i);
			}

			bool removed = false;
			for2(i, j, n, m)
			{
				if (a[i][j] == 1)
				{
					int cnt = 0;
					for1(k, 4)
					{
						int nx = i + dd[0][k];
						int ny = j + dd[1][k];
						step(nx, ny, n, m);

						if (a[nx][ny] == 0 && outside[nx][ny])
						{
							cnt += 1;
							if (cnt >= 2)
							{
								a[i][j] = 0;
								removed = true;
								break;
							}
						}
					}
				}
			}

			if (removed == false)
				break;

			t += 1;
		}

		cout << t;
		return 0;
	}
};