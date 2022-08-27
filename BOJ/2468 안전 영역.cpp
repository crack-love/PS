// https://www.acmicpc.net/problem/2468

#include <bits/stdc++.h>
using namespace std;

struct p2468
{
	const int dx[4]{ 0, 0, 1, -1 };
	const int dy[4]{ 1, -1, 0, 0 };

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n;
		int og[100][100];
		int minv = 1e9, maxv = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> og[i][j];
				minv = min(minv, og[i][j]);
				maxv = max(maxv, og[i][j]);
			}
		}

		// each level of water
		int answer = 0;
		int g[100][100];
		vector<pair<int, int>> v;
		for (int h = minv - 1; h <= maxv; ++h)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					g[i][j] = og[i][j] <= h ? 0 : 1;
				}
			}

			int dstCnt = 0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (g[i][j] == 1)
					{
						// dfs
						v.push_back({ i, j });
						g[i][j] = 0;
						dstCnt += 1;
						while (!v.empty())
						{
							auto [x, y] = v.back();
							v.pop_back();

							for (int i = 0; i < 4; ++i)
							{
								int nx = x + dx[i];
								int ny = y + dy[i];
								if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
								if (g[nx][ny] == 0) continue;
								g[nx][ny] = 0;
								v.push_back({ nx, ny });
							}
						}
					}
				}

				answer = max(answer, dstCnt);
			}
		}
		cout << answer;
		return 0;
	}
};