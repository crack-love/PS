// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

struct p10026
{
	int groups(char map[][101], int n, vector<vector<char>> t)
	{
		bool visit[100][100] = {};
		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		queue<pair<int, int>> q;

		// get group count for each type
		int gcnt = 0;
		for (int ti = 0; ti < (int)t.size(); ++ti)
		{
			while (true)
			{
				// find unvisited node
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						if (visit[i][j]) continue;

						for (int k = 0; k < (int)t[ti].size(); ++k)
						{
							if (map[i][j] == t[ti][k])
							{
								q.push({ i, j });
								visit[i][j] = true;
								gcnt += 1;
								i = j = k = n;
								break;
							}
						}
					}
				}
				if (q.empty())
				{
					break;
				}

				// bfs
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (visit[nx][ny]) continue;

						bool isMatch = false;
						for (int j = 0; j < (int)t[ti].size(); ++j)
						{
							if (map[nx][ny] == t[ti][j])
							{
								isMatch = true;
								break;
							}
						}
						if (!isMatch) continue;

						visit[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
		}

		return gcnt;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		char map[100][101];
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
		}

		cout << groups(map, n, { {'R'}, {'G'}, {'B'} }) << " ";
		cout << groups(map, n, { {'R', 'G'}, {'B'} });

		return 0;
	}
};