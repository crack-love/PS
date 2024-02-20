// https://www.acmicpc.net/problem/15683

#include <bits/stdc++.h>
using namespace std;

struct p15683
{
	int n, m;
	char g[8][8]{};
	vector<tuple<int, int, vector<int>>> cc; // x, y, dirs

	const int dx[4]{ 0, 1, 0, -1 };
	const int dy[4]{ 1, 0, -1, 0 };
	const vector<int> initDir[5]{ {0}, {0, 2}, {0, 3}, {0, 2, 3}, {0, 1, 2, 3} };
	const int rotSize[5]{ 4, 2, 4, 4, 1 }; // how many rot
	int maxView = 0;

	int getViewCnt()
	{
		int visit[8][8]{};
		int viewCnt = 0;
		for (int i = 0; i < cc.size(); ++i)
		{
			const auto& [x, y, dirs] = cc[i];
			for (int j = 0; j < dirs.size(); ++j)
			{
				int d = dirs[j];
				int nx = x, ny = y;
				while (nx >= 0 && ny >= 0 && nx < n && ny < m)
				{
					if (g[nx][ny] == '6') break;
					if (g[nx][ny] == '#') break;
					if (g[nx][ny] == '0' && !visit[nx][ny])
					{
						visit[nx][ny] = 1;
						viewCnt += 1;
					}
					nx = nx + dx[d];
					ny = ny + dy[d];
				}
			}
		}
		return viewCnt;
	}

	void rotate(int ci)
	{
		if (ci >= cc.size())
		{
			int vc = getViewCnt();
			if (vc > maxView)
			{
				maxView = vc;
			}
			return;
		}

		auto& [x, y, dir] = cc[ci];
		int rs = rotSize[g[x][y] - 1 - '0'];
		for (int i = 0; i < rs; ++i)
		{
			for (int j = 0; j < dir.size(); ++j)
			{
				dir[j] = (dir[j] + 1) % 4;
			}

			rotate(ci + 1);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int emptyCnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				char x;
				cin >> x;
				g[i][j] = x;
				if ('1' <= x && x <= '5')
				{
					cc.push_back({ i, j, initDir[x - 1 - '0'] });
				}
				else if (x == '0')
				{
					++emptyCnt;
				}
			}
		}

		rotate(0);

		cout << emptyCnt - maxView;
		return 0;
	}
};