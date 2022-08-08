// https://www.acmicpc.net/problem/9020

#include <bits/stdc++.h>
using namespace std;

struct p9020
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int isNotPrime[10001] = {};
		vector<int> ps;
		for (int i = 2; i <= 10000; ++i)
		{
			if (!isNotPrime[i])
			{
				ps.push_back(i);
				for (int j = i; j <= 10000; j += i)
				{
					isNotPrime[j] = 1;
				}
			}
		}

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			int ans0 = 0;
			int ans1 = 0;
			int mindiff = 1e9;

			for (int i = 0; i < ps.size(); ++i)
			{
				for (int j = i; j < ps.size(); ++j)
				{
					if (ps[i] + ps[j] > n)
					{
						break;
					}
					else if (ps[i] + ps[j] == n)
					{
						if (mindiff > ps[j] - ps[i])
						{
							ans0 = ps[i];
							ans1 = ps[j];
							mindiff = ans1 - ans0;
							break;
						}
					}
				}
			}

			cout << ans0 << ' ' << ans1 << '\n';
		}

		return 0;
	}
};