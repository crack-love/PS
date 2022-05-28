// https://www.acmicpc.net/problem/14938

#include <iostream>
using namespace std;

struct p14938
{
	int main()
	{
		int items[101] = {};
		int e[101][101] = {};

		int n, m, r;
		cin >> n >> m >> r;
		for (int i = 1; i <= n; ++i)
		{
			cin >> items[i];
		}
		for (int i = 0; i < r; ++i)
		{
			int a, b, l;
			cin >> a >> b >> l;
			e[a][b] = l;
			e[b][a] = l;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (e[j][i] == 0) continue;

				for (int k = j + 1; k <= n; ++k)
				{
					if (e[i][k] == 0) continue;

					int nv = e[j][i] + e[i][k];
					if (nv < e[j][k] || e[j][k] == 0)
					{
						e[j][k] = e[k][j] = nv;
					}
				}
			}
		}

		int answer = 0;
		for (int i = 1; i <= n; ++i)
		{
			int sum = items[i];
			for (int j = 1; j <= n; ++j)
			{
				if (i == j) continue;

				if (e[i][j] <= m && e[i][j] != 0)
				{
					sum += items[j];
				}
			}

			if (sum > answer)
			{
				answer = sum;
			}
		}

		cout << answer;
		return 0;
	}
};