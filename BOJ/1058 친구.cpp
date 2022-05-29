// https://www.acmicpc.net/problem/1058
// silver2

#include <iostream>
using namespace std;

struct p1058
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		char e[50][51] = {};
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> e[i];
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (e[i][j] != 'Y') continue;
				for (int k = j + 1; k <= n; ++k)
				{
					if (e[i][k] != 'Y') continue;

					if (e[j][k] == 'N')
					{
						e[j][k] = e[k][j] = 'F';
					}
				}
			}
		}

		int maxCnt = 0;
		for (int i = 0; i < n; ++i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
			{
				cnt += e[i][j] != 'N';
			}

			if (cnt > maxCnt)
			{
				maxCnt = cnt;
			}
		}

		cout << maxCnt;
		return 0;
	}
};