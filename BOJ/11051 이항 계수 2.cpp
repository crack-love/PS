// https://www.acmicpc.net/problem/11051

#include <iostream>
using namespace std;

struct p11051
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, k;
		cin >> n >> k;

		// ÆÄ½ºÄ®ÀÇ »ï°¢Çü
		int d[1001][1001] = {};
		for (int i = 0; i <= n; ++i)
		{
			d[i][0] = d[i][i] = 1;
		}
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
				d[i][j] %= 10007;
			}
		}

		cout << d[n][k];

		return 0;
	}
};