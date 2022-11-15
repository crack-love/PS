// https://www.acmicpc.net/problem/17070

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p17070
{
	int n;
	int a[16][16];
	int answer = 0;
	int rightside[3][2] = { {0,1},{1,0},{1,1} };
	vector<int> dirto[3] = { {0, 2}, {1, 2}, {0, 1, 2} };
	vector<pair<int, int>> dirvalid[3] = { {{0,1}}, {{1,0}}, {{0,1},{1,0},{1,1}} };

	void move(int x, int y, int dir)
	{
		int rx = x + rightside[dir][0];
		int ry = y + rightside[dir][1];
		if (rx == n - 1 && ry == n - 1)
		{
			answer += 1;
			return;
		}

		for (int dto : dirto[dir])
		{
			bool fail = false;
			for (pair<int, int> p : dirvalid[dto])
			{
				int nx = rx + p.first;
				int ny = ry + p.second;
				if (nx >= n || ny >= n || a[nx][ny] != 0)
				{
					fail = true;
					break;
				}
			}
			if (!fail)
			{
				a[x][y] = dir + 2;
				move(rx, ry, dto);
				a[x][y] = 0;
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for2(i, j, n, n)
		{
			cin >> a[i][j];
		}

		move(0, 0, 0);
		cout << answer;
		return 0;
	}
};