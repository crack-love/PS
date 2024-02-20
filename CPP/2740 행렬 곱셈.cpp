// https://www.acmicpc.net/problem/2740

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2740
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m, k;
		int a[100][100], b[100][100];
		cin >> n >> m;
		for2(i, j, n, m)
		{
			cin >> a[i][j];
		}
		cin >> m >> k;
		for2(i, j, m, k)
		{
			cin >> b[i][j];
		}
		int c[100][100]{};
		for (int ai = 0; ai < n; ++ai)
		{
			for (int aj = 0; aj < m; ++aj)
			{
				for (int bj = 0; bj < k; ++bj)
				{
					c[ai][bj] += a[ai][aj] * b[aj][bj];
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				cout << c[i][j] << " ";
			}
			cout << "\n";
		}

		return 0;
	}
};