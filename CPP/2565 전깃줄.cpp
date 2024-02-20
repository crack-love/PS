// https://www.acmicpc.net/problem/2565

#include <bits/stdc++.h>
using namespace std;

struct p2565
{
	// LIS MAN

	int dp[502];
	int cnt = 0;

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		vector<pair<int, int>> arr;
		int e;
		cin >> e;
		for (int i = 0; i < e; ++i)
		{
			int a, b;
			cin >> a >> b;
			arr.push_back({ a, b });
		}
		sort(arr.begin(), arr.end());

		for (int i = 0; i < e; ++i)
		{
			auto [a, b] = arr[i];

			if (cnt == 0)
			{
				dp[cnt++] = b;
			}
			else
			{
				int* p = upper_bound(dp, dp + cnt, b);
				if (*p == 0)
				{
					dp[cnt++] = b;
				}
				else
				{
					*p = b;
				}
			}
		}

		cout << e - cnt;
	}
};