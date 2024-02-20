// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
using namespace std;

struct p7575
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		// pattern from pg0, circular -> 1000
		// each pg 100, reverse 100, match pattern = 1000*200*1000

		int n, k; // n[2, 100], k[4, 1000]
		cin >> n >> k;

		vector<int> pg[100];
		for (int i = 0; i < n; ++i)
		{
			int m; // m[10, 1000]
			cin >> m;
			pg[i].resize(m);
			for (int j = 0; j < m; ++j)
			{
				cin >> pg[i][j];
			}
		}

		auto pgv = [&pg](int i)
		{
			return pg[0][i % pg[0].size()];
		};

		for (int ptbeg = 0; ptbeg < pg[0].size() - k + 1; ++ptbeg) // 1000
		{
			vector<int> pt(pg[0].size(), 0);
			int j = 0;
			for (int i = 1; i < pg[0].size(); ++i)
			{
				while (j > 0 && pg[0][i] != pg[0][j])
				{
					j = pt[j - 1];
				}
				if (pg[0][i] == pg[0][j])
				{
					pt[i] = ++j;
				}
			}

			bool isAllPgMatch = false;

			for (int pgi = 1; pgi < n; ++pgi) // 100
			{
				bool isPgMatch = false;

				// pg
				int j = 0;
				for (int i = 0; i < pg[pgi].size(); ++i) // 1000
				{
					while (j > 0 && pg[pgi][i] != pgv(ptbeg + j))
					{
						j = pt[j - 1];
					}
					if (pg[pgi][i] == pgv(ptbeg + j))
					{
						++j;
						if (j >= k)
						{
							isPgMatch = true;
							break;
						}
					}
				}
				if (!isPgMatch)
				{
					// reverse
					j = 0;
					for (int i = pg[pgi].size() - 1; i >= 0; --i) // 1000
					{
						while (j > 0 && pg[pgi][i] != pgv(ptbeg + j))
						{
							j = pt[j - 1];
						}
						if (pg[pgi][i] == pgv(ptbeg + j))
						{
							++j;
							if (j >= k)
							{
								isPgMatch = true;
								break;
							}
						}
					}
				}

				if (!isPgMatch)
				{
					break;
				}
				else if (pgi == n - 1)
				{
					isAllPgMatch = true;
				}
			}

			if (isAllPgMatch)
			{
				cout << "YES";
				return 0;
			}
		}

		cout << "NO";
		return 0;
	}
};