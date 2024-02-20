// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct p9251
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int dp[1001][1001] = {};
		string a, b;
		cin >> a >> b;

		for (int i = 1; i <= a.size(); ++i)
		{
			for (int j = 1; j <= b.size(); ++j)
			{
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		cout << dp[a.size()][b.size()];

		return 0;
	}
};