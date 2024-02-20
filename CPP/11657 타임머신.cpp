// https://www.acmicpc.net/problem/11657
// gold4

#include <iostream>
#include <climits>
using namespace std;

struct p11657
{
	int main()
	{
		long long INF = LLONG_MAX;
		long long w[501] = {};
		int e[6001][3] = {};

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> e[i][0] >> e[i][1] >> e[i][2];
		}

		for (int i = 0; i <= n; ++i)
		{
			w[i] = INF;
		}
		w[1] = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int u = e[j][0];
				int v = e[j][1];
				int c = e[j][2];
				if (w[u] == INF) continue;

				if (w[u] + c < w[v])
				{
					if (i == n - 1)
					{
						cout << -1;
						return 0;
					}
					else
					{
						w[v] = w[u] + c;
					}
				}
			}
		}

		for (int i = 2; i <= n; ++i)
		{
			if (i != 2) cout << "\n";

			if (w[i] == INF)
			{
				cout << -1;
			}
			else
			{
				cout << w[i];
			}
		}

		return 0;
	}
};