// https://www.acmicpc.net/problem/1780

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p1780
{
	int g[2187][2187];
	int cnt[3];

	void divide(int i, int j, int size)
	{
		int val = g[i][j];
		for2(u, v, size, size)
		{
			if (g[i + u][j + v] != val)
			{
				int ns = size / 3;
				for2(n, m, 3, 3)
				{
					divide(i + n * ns, j + m * ns, ns);
				}
				return;
			}
		}
		cnt[val + 1] += 1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		for2(i, j, n, n)
		{
			cin >> g[i][j];
		}

		divide(0, 0, n);

		for (int i = 0; i < 3; ++i)
		{
			cout << cnt[i] << "\n";
		}

		return 0;
	}
};