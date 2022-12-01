// https://www.acmicpc.net/problem/1890

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1890
{
	int n;
	int a[100][100];
	long long d[100][100]{};

	long long dp(int x, int y)
	{
		long long& ret = d[x][y];
		if (ret != 0)
		{
			return ret;
		}

		for (int i = 1; i <= x; ++i)
		{
			if (i == a[x - i][y])
			{
				ret += dp(x - i, y);
			}
		}
		for (int i = 1; i <= y; ++i)
		{
			if (i == a[x][y - i])
			{
				ret += dp(x, y - i);
			}
		}
		return ret;
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

		d[0][0] = 1;
		cout << dp(n - 1, n - 1);

		return 0;
	}
};