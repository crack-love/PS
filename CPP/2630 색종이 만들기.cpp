// https://www.acmicpc.net/problem/2630

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p2630
{
	int g[128][128];
	int cnt[2];

	void cut(int x, int y, int size)
	{
		int color = g[x][y];

		for2(i, j, size, size)
		{
			if (g[x + i][y + j] != color)
			{
				int s = size / 2;
				cut(x, y, s);
				cut(x + s, y, s);
				cut(x, y + s, s);
				cut(x + s, y + s, s);
				return;
			}
		}

		cnt[color] += 1;
	}

	int main()
	{
		int n;
		cin >> n;
		for2(i, j, n, n)
		{
			cin >> g[i][j];
		}

		cut(0, 0, n);

		cout << cnt[0] << "\n" << cnt[1] << "\n";
		return 0;
	}
};