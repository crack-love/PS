// https://www.acmicpc.net/problem/14889

#include <bits/stdc++.h>
using namespace std;

struct p14889
{
	int n;
	int a[20][20];
	int pickeds[20];
	int answer = 1e9;

	void pick(int i, int pcnt, int lsum, int rsum)
	{
		if (i >= n)
		{
			if (pcnt == n / 2 && answer > abs(lsum - rsum))
			{
				answer = abs(lsum - rsum);
			}
			return;
		}

		if (pcnt + 1 <= n / 2)
		{
			int addsum = 0;
			int subsum = 0;
			for (int j = 0; j < n; ++j)
			{
				if (pickeds[j])
				{
					addsum += a[i][j] + a[j][i];
				}
				else
				{
					subsum += a[i][j] + a[j][i];
				}
			}

			pickeds[i] = 1;
			pick(i + 1, pcnt + 1, lsum + addsum, rsum - subsum);
			pickeds[i] = 0;
		}

		if (pcnt == n / 2)
		{
			i = n - 1;
		}
		pick(i + 1, pcnt, lsum, rsum);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> a[i][j];
			}
		}

		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				sum += a[i][j] + a[j][i];
			}
		}

		pick(0, 0, 0, sum);
		cout << answer;
		return 0;
	}
};