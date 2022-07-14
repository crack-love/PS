// https://www.acmicpc.net/problem/2665

#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

struct p2665
{
	// 01-bfs

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		char map[50][51];
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> map[i];
		}

		int visit[50][50] = {};
		deque<tuple<int, int, int>> q;
		q.push_back({ 0, 0, (map[0][0] == '1' ? 0 : 1) });
		visit[0][0] = 1;

		while (!q.empty())
		{
			int x, y, c;
			tie(x, y, c) = q.front();
			q.pop_front();

			if (x == n - 1 && y == n - 1)
			{
				cout << c;
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (visit[nx][ny]) continue;

				visit[nx][ny] = 1;
				if (map[nx][ny] == '1')
				{
					q.push_front({ nx, ny, c });
				}
				else
				{
					q.push_back({ nx, ny, c + 1 });
				}
			}
		}

		return 0;
	}
};