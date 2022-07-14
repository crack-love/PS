// https://www.acmicpc.net/problem/4485

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct p4485_dijk
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		struct node
		{
			int x, y, c;
			const bool operator < (const node& b) const { return c > b.c; }
		};

		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		int map[125][125];
		int cost[125][125] = {};
		priority_queue<node> q;

		int t = 0;
		while (++t)
		{
			fill(&cost[0][0], &cost[124][125], -1);
			while (!q.empty()) q.pop();

			int n; // [2 125]
			cin >> n;
			if (n == 0)
			{
				break;
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					cin >> map[i][j];
				}
			}

			q.push({ 0, 0, map[0][0] });
			cost[0][0] = map[0][0];

			bool isFinished = false;
			while (!q.empty() && !isFinished)
			{
				int x = q.top().x;
				int y = q.top().y;
				int c = q.top().c; q.pop();
				if (cost[x][y] != c) continue;

				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

					int nc = c + map[nx][ny];
					if (cost[nx][ny] == -1 || nc < cost[nx][ny])
					{
						cost[nx][ny] = nc;
						q.push({ nx, ny, nc });

						if (nx == n - 1 && ny == n - 1)
						{
							cout << "Problem " << t << ": " << nc << "\n";
							isFinished = true;
							break;
						}
					}
				}
			}
		}

		return 0;
	}
};