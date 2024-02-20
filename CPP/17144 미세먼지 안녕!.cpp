// https://www.acmicpc.net/problem/17144

#include <bits/stdc++.h>
using namespace std;

struct p17144
{
	int r, c, t;
	int g[50][50];
	int gt[50][50];
	const int dx[4] = { 0, -1, 0, 1 };
	const int dy[4] = { 1, 0, -1, 0 };
	enum dirname { R, U, L, D };

	void extend()
	{
		copy(&g[0][0], &g[r - 1][c], &gt[0][0]);

		vector<pair<int, int>> dst;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (g[i][j] <= 0) continue;

				dst.clear();
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (g[nx][ny] == -1) continue; // pass -1
					dst.push_back({ nx, ny });
				}

				int v = g[i][j] / 5;
				for (const pair<int, int>& p : dst)
				{
					gt[p.first][p.second] += v;
				}
				gt[i][j] -= dst.size() * v;
			}
		}

		copy(&gt[0][0], &gt[r - 1][c], &g[0][0]);
	}

	void flow(int i, int j, int borderi, vector<int>& dirs)
	{
		int nx = i + dx[dirs[0]];
		int ny = j + dy[dirs[0]];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c || nx == borderi)
		{
			dirs.erase(dirs.begin());
			if (dirs.size() > 0)
			{
				flow(i, j, borderi, dirs);
			}
		}
		else
		{
			if (g[i][j] != -1 && g[nx][ny] != -1)
			{
				g[i][j] = g[nx][ny];
				g[nx][ny] = 0;
			}
			flow(nx, ny, borderi, dirs);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		pair<int, int> p0 = { -1, -1 }, p1;
		cin >> r >> c >> t;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin >> g[i][j];
				if (g[i][j] == -1)
				{
					(p0.first == -1 ? p0 : p1) = { i,j };
				}
			}
		}

		while (t--)
		{
			vector<int> d0 = { U, R, D, L };
			vector<int> d1 = { D, R, U, L };

			extend();
			flow(p0.first, p0.second, p0.first + 1, d0);
			flow(p1.first, p1.second, p1.first - 1, d1);
		}

		int sum = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (g[i][j] > 0)
					sum += g[i][j];
			}
		}
		cout << sum;

		return 0;
	}
};