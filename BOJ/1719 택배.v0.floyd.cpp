// https://www.acmicpc.net/problem/1719

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

struct p1719
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int e[1001][1001];
		int p[1001][1001];
		fill(&e[0][0], &e[1000][1001], -1);
		fill(&p[0][0], &p[1000][1001], -1);

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			e[a][b] = e[b][a] = c;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (e[j][i] == -1) continue;
				for (int k = 1; k <= n; ++k)
				{
					if (e[i][k] == -1) continue;

					int nc = e[j][i] + e[i][k];
					if (e[j][k] == -1 || nc < e[j][k])
					{
						e[j][k] = e[k][j] = nc;

						if (p[j][i] != -1) p[j][k] = p[j][i];
						else p[j][k] = i;
						if (p[k][i] != -1) p[k][j] = p[k][i];
						else p[k][j] = i;
					}
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == j || e[i][j] == -1)
				{
					cout << "-";
				}
				else if (p[i][j] == -1)
				{
					cout << j;
				}
				else
				{
					cout << p[i][j];
				}

				cout << " ";
			}

			cout << "\n";
		}

		return 0;
	}
};