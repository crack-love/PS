// https://www.acmicpc.net/problem/1613
// gold3

#include <iostream>
using namespace std;

struct p1613
{
	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		int e[401][401] = {};

		int n, k;
		cin >> n >> k;
		for (int i = 0; i < k; ++i)
		{
			int a, b;
			cin >> a >> b;
			e[a][b] = -1;
			e[b][a] = 1;
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


		int s;
		cin >> s;
		for (int i = 0; i < s; ++i)
		{
			int a, b;
			cin >> a >> b;
			cout << e[a][b] << "\n";
		}

		return 0;
	}
};