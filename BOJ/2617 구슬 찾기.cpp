// https://www.acmicpc.net/problem/2617
// glod5

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct p2617
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int e[100][100] = {};

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			e[a][b] = 1;
			e[b][a] = -1;
		}

		if (n == 1)
		{
			cout << 0;
			return 0;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (e[i][j] == 0) continue;
				for (int k = j + 1; k <= n; ++k)
				{
					if (e[i][k] == 0) continue;

					int ji = e[j][i];
					int ik = e[i][k];
					int jk = e[j][k];

					if (ji < 0 && ik < 0)
					{
						if (e[j][k] == 0 || (ji + ik > e[j][k]))
						{
							e[j][k] = ji + ik;
							e[k][j] = -(ji + ik);
						}
					}
					else if (ji > 0 && ik > 0)
					{
						if (e[j][k] == 0 || (ji + ik < e[j][k]))
						{
							e[j][k] = ji + ik;
							e[k][j] = -(ji + ik);
						}
					}
				}
			}
		}

		int answer = 0;
		int mid = (n + 1)/ 2;
		for (int i = 1; i <= n; ++i)
		{
			int lcnt = 0;
			int rcnt = 0;

			for (int j = 1; j <= n; ++j)
			{
				if (i == j) continue;

				if (e[i][j] < 0) ++lcnt;
				else if (e[i][j] > 0) ++rcnt;
			}

			if (lcnt >= mid || rcnt >= mid)
			{
				++answer;
			}
		}

		cout << answer;
		return 0;
	}
};