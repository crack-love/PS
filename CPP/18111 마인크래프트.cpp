// https://www.acmicpc.net/problem/18111

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p18111
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m, b;
		cin >> n >> m >> b;
		int a[500][500];
		int maxh = 0;
		for2(i, j, n, m)
		{
			cin >> a[i][j];
			maxh = max(maxh, a[i][j]);
		}

		int ansCost = 256 * 500 * 500 * 2;
		int ansHeight = 0;
		for (int h = maxh; h >= 0; --h)
		{
			int cost = 0;
			int stock = b;
			for2(i, j, n, m)
			{
				if (a[i][j] > h)
				{
					int d = a[i][j] - h;
					cost += d * 2;
					stock += d;
				}
				else
				{
					int d = h - a[i][j];
					cost += d;
					stock -= d;
				}
			}

			if (stock >= 0 && cost < ansCost)
			{
				ansCost = cost;
				ansHeight = h;
			}
		}

		cout << ansCost << " " << ansHeight;
		return 0;
	}
};