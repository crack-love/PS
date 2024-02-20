// https://www.acmicpc.net/problem/16234

#include <bits/stdc++.h>
using namespace std;

struct p16234
{
	const int dx[4]{ 0, -1, 0, 1 };
	const int dy[4]{ -1, 0, 1, 0 };
	int n, l, r;
	int g[50][50];
	bool visited[50][50];
	vector<vector<pair<int, int>>> sets;
	vector<int> setsum;

	void dfs(int x, int y, int gi)
	{
		visited[x][y] = true;
		sets[gi].push_back({ x,y });
		setsum[gi] += g[x][y];

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny]) continue;
			int df = abs(g[x][y] - g[nx][ny]);
			if (l <= df && df <= r)
			{
				dfs(nx, ny, gi);
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		cin >> n >> l >> r;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> g[i][j];
			}
		}

		int answer = 0;
		while (true)
		{
			memset(visited, 0, sizeof(visited));
			for (int i = 0; i < sets.size(); ++i)
			{
				sets[i].clear();
				setsum[i] = 0;
			}

			int groupIdx = -1;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (visited[i][j]) continue;
					for (int k = 2; k <= 3; ++k)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (visited[nx][ny]) continue;
						int df = abs(g[i][j] - g[nx][ny]);
						if (l <= df && df <= r)
						{
							++groupIdx;
							if (sets.size() < groupIdx + 1)
							{
								sets.push_back({});
								setsum.push_back(0);
							}

							dfs(i, j, groupIdx);
						}
					}
				}
			}

			if (groupIdx == -1)
			{
				break;
			}
			else
			{
				answer += 1;

				for (int i = 0; i < groupIdx + 1; ++i)
				{
					int divided = setsum[i] / sets[i].size();
					for (auto& [x, y] : sets[i])
					{
						g[x][y] = divided;
					}
				}
			}
		}

		cout << answer;
		return 0;
	}
};