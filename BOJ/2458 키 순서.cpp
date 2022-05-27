// https://www.acmicpc.net/problem/2458
// gold4

#include <iostream>
using namespace std;

struct p2458
{
	int main()
	{
		int e[501][501] = {};

		int n, m; // n[2 500]
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			e[a][b] = 1;
			e[b][a] = 2;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (!e[j][i]) continue;

				for (int k = j + 1; k <= n; ++k)
				{
					if (e[j][i] == e[i][k])
					{
						e[j][k] = e[i][k];
						e[k][j] = e[k][i];
					}
				}
			}
		}

		int answer = 0;
		for (int i = 1; i <= n; ++i)
		{
			bool ok = true;
			for (int j = 1; j <= n && ok; ++j)
			{
				if (i == j) continue;

				if (!e[i][j])
				{
					ok = false;
				}
			}
			answer += ok;
		}

		cout << answer;
		return 0;
	}
};