// https://www.acmicpc.net/problem/1146
// platinum5

#include <iostream>
#include <cstring>
using namespace std;

int p1146()
{
	int n;
	cin >> n;
	int d0[2][100][100] = {};
	int d1[2][100][100] = {};
	enum order { asc, des };
	int MOD = 1000000;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	// init
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;

			if (i < j) // 01
			{
				d0[asc][j - 1][n - 1 - j] += 1;
			}
			else if (i > j) // 10
			{
				d0[des][j][n - 1 - j - 1] += 1;
			}
		}
	}


	for (int col = 2; col < n; ++col)
	{
		memset(d1, 0, sizeof(d1));

		for (int l = 0; l < n; ++l)
		{
			int r = n - col - l;

			// to ascent
			for (int i = 1; i <= r; ++i)
			{
				int nl = l + i - 1;
				int nr = r - i;
				d1[asc][nl][nr] += d0[des][l][r];
				d1[asc][nl][nr] %= MOD;
			}

			// to descent
			for (int i = 1; i <= l; ++i)
			{
				int nl = l - i;
				int nr = r + i - 1;
				d1[des][nl][nr] += d0[asc][l][r];
				d1[des][nl][nr] %= MOD;
			}
		}

		memcpy(d0, d1, sizeof(d1));
	}

	int ans = 0;
	for (int k = 0; k < 2; ++k)
	{
		ans += d0[k][0][0];
		ans %= MOD;
	}

	cout << ans;
	return 0;
}