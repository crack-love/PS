// https://www.acmicpc.net/problem/12100

#include <iostream>
#include <algorithm>
using namespace std;

struct p12100
{
	int n;
	int map[20][20];
	int maxBlock = 0;

	bool shiftLeft()
	{
		bool merged[20][20] = {};
		bool changed = false;

		for (int i = 0; i < n; ++i)
		{
			// shift spaces
			for (int j = 0; j < n; ++j)
			{
				if (map[i][j] == 0) continue;

				int nj = j;
				while (nj > 0 && map[i][nj - 1] == 0)
				{
					nj -= 1;
				}

				if (nj != j)
				{
					map[i][nj] = map[i][j];
					map[i][j] = 0;
					changed |= true;
				}

				if (nj > 0 && map[i][nj - 1] == map[i][nj])
				{
					if (!merged[i][nj - 1])
					{
						map[i][nj - 1] *= 2;
						map[i][nj] = 0;
						merged[i][nj - 1] = true;
						changed |= true;
					}
				}
			}
		}

		return changed;
	}

	bool shiftRight()
	{
		bool merged[20][20] = {};
		bool changed = false;

		for (int i = 0; i < n; ++i)
		{
			// shift spaces
			for (int j = n - 1; j >= 0; --j)
			{
				if (map[i][j] == 0) continue;

				int nj = j;
				while (nj + 1 < n && map[i][nj + 1] == 0)
				{
					nj += 1;
				}

				if (nj != j)
				{
					map[i][nj] = map[i][j];
					map[i][j] = 0;
					changed |= true;
				}

				if (nj + 1 < n && map[i][nj + 1] == map[i][nj])
				{
					if (!merged[i][nj + 1])
					{
						map[i][nj + 1] *= 2;
						map[i][nj] = 0;
						merged[i][nj + 1] = true;
						changed |= true;
					}
				}
			}
		}

		return changed;
	}

	bool shiftUp()
	{
		bool merged[20][20] = {};
		bool changed = false;

		for (int i = 0; i < n; ++i)
		{
			// shift spaces
			for (int j = 0; j < n; ++j)
			{
				if (map[i][j] == 0) continue;

				int ni = i;
				while (ni > 0 && map[ni - 1][j] == 0)
				{
					ni -= 1;
				}

				if (ni != i)
				{
					map[ni][j] = map[i][j];
					map[i][j] = 0;
					changed |= true;
				}

				if (0 <= ni - 1 && map[ni - 1][j] == map[ni][j])
				{
					if (!merged[ni - 1][j])
					{
						map[ni - 1][j] *= 2;
						map[ni][j] = 0;
						merged[ni - 1][j] = true;
						changed |= true;
					}
				}
			}
		}

		return changed;
	}

	bool shiftDown()
	{
		bool merged[20][20] = {};
		bool changed = false;

		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (map[i][j] == 0) continue;

				int ni = i;
				while (ni + 1 < n && map[ni + 1][j] == 0)
				{
					ni += 1;
				}

				if (ni != i)
				{
					map[ni][j] = map[i][j];
					map[i][j] = 0;
					changed |= true;
				}

				if (ni + 1 < n && map[ni + 1][j] == map[ni][j])
				{
					if (!merged[ni + 1][j])
					{
						map[ni + 1][j] *= 2;
						map[ni][j] = 0;
						merged[ni + 1][j] = true;
						changed |= true;
					}
				}
			}
		}

		return changed;
	}

	void move(int cnt)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				maxBlock = max(maxBlock, map[i][j]);
			}
		}

		if (cnt == 5)
		{
			return;
		}

		int omap[20][20];

		for (int i = 0; i < 4; ++i)
		{
			copy(&map[0][0], &map[n - 1][n], &omap[0][0]);

			if (i == 0 && !shiftLeft()) continue;
			else if (i == 1 && !shiftRight())continue;
			else if (i == 2 && !shiftUp()) continue;
			else if (i == 3 && !shiftDown()) continue;

			move(cnt + 1);

			copy(&omap[0][0], &omap[n - 1][n], &map[0][0]);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> map[i][j];
			}
		}

		move(0);
		cout << maxBlock;

		return 0;
	}
};