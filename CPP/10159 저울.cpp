// https://www.acmicpc.net/problem/10159
// gold3

#include <iostream>
using namespace std;

struct p10159
{
	int main()
	{
		int e[101][101] = {};

		int n, m;
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
				if (e[j][i] == 0) continue;

				for (int k = j + 1; k <= n; ++k)
				{
					if (e[i][k] == 0) continue;

					if (e[j][i] == e[i][k])
					{
						e[j][k] = e[j][i];
						e[k][j] = e[i][j];
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			int ans = 0;
			for (int j = 1; j <= n; ++j)
			{
				if (i == j) continue;

				ans += (e[i][j] == 0);
			}
			cout << ans << "\n";
		}

		return 0;
	}
};