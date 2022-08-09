// https://www.acmicpc.net/problem/14889

#include <bits/stdc++.h>
using namespace std;

struct p14889_permu
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int a[20][20];
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> a[i][j];
			}
		}

		vector<int> p(n, 1);
		for (int i = 0; i < n / 2; ++i)
		{
			p[i] = 0;
		}

		int answer = (int)1e9;
		do
		{
			int sum[2] = {};

			for (int i = 0; i < n; ++i)
			{
				for (int j = i + 1; j < n; ++j)
				{
					if (p[j] == p[i])
					{
						sum[p[i]] += a[i][j] + a[j][i];
					}
				}
			}

			int diff = abs(sum[0] - sum[1]);
			answer = min(answer, diff);
		} while (next_permutation(p.begin(), p.end()));

		cout << answer;
		return 0;
	}
};