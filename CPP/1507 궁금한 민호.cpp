// https://www.acmicpc.net/problem/1507

#include <iostream>
using namespace std;

struct p1507
{
	int main()
	{
		int d0[20][20];

		// get input
		int n; // [1 20]
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> d0[i][j];
			}
		}

		// d0 floyd warshall
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j) continue;
				for (int k = j + 1; k < n; ++k)
				{
					if (i == k || j == k) continue;

					int nd = d0[j][i] + d0[i][k];
					if (nd < d0[j][k])
					{
						// exit
						cout << -1;
						return 0;
					}
				}
			}
		}

		// remove mid edge
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (d0[i][j] <= 0) continue;
				for (int k = j + 1; k < n; ++k)
				{
					if (d0[i][k] <= 0 || d0[j][k] <= 0) continue;
					if (d0[j][i] + d0[i][k] == d0[j][k])
					{
						d0[j][k] = d0[k][j] = -1;
					}
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (d0[i][j] > 0)
					sum += d0[i][j];
			}
		}
		cout << sum;
	}
};