// https://www.acmicpc.net/problem/2580

#include <iostream>
using namespace std;

struct p2580
{
	static const int n = 9;
	int map[n][n];
	int row[n][10];
	int col[n][10];
	int sqr[n][10];

	int sqrIdx(int i, int j)
	{
		return ((i / 3) * 3) + (j / 3);
	}

	bool fill(int i, int j)
	{
		if (j >= n) { j = 0;  i += 1; }
		if (i >= n) { return true; }
		if (map[i][j] != 0) { return fill(i, j + 1); }

		for (int k = 1; k <= 9; ++k)
		{
			if (row[i][k] == 0 &&
				col[j][k] == 0 &&
				sqr[sqrIdx(i, j)][k] == 0)
			{
				row[i][k] = col[j][k] = sqr[sqrIdx(i, j)][k] = 1;
				map[i][j] = k;
				if (fill(i, j + 1))
				{
					return true;
				}
				row[i][k] = col[j][k] = sqr[sqrIdx(i, j)][k] = 0;
				map[i][j] = 0;
			}
		}

		return false;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int x;
				cin >> x;
				map[i][j] = x;
				row[i][x] = 1;
				col[j][x] = 1;
				sqr[sqrIdx(i, j)][x] = 1;
			}
		}

		fill(0, 0);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}

		return 0;
	}
};