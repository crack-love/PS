// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
using namespace std;

struct p3190
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int map[101][101] = {};
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < k; ++i)
		{
			int r, c;
			cin >> r >> c;
			map[r][c] = 1;
		}

		char cmd[10001] = {};
		int l;
		cin >> l;
		for (int i = 0; i < l; ++i)
		{
			int t, r;
			cin >> t;
			cin >> cmd[t];
		}

		const int dx[] = { 0, 1, 0, -1 }; // r, d, l, u
		const int dy[] = { 1, 0, -1, 0 };
		int hx = 1, hy = 1;
		int tx = 1, ty = 1;
		int t = 1;
		map[hx][hy] = 10;

		while (true)
		{
			int hdir = map[hx][hy] - 10;
			int nx = hx + dx[hdir];
			int ny = hy + dy[hdir];

			// out of map
			if (nx < 1 || ny < 1 || nx > n || ny > n)
			{
				break;
			}

			// hit self
			if (map[nx][ny] >= 10)
			{
				break;
			}

			// move head
			int nv = map[nx][ny];
			map[nx][ny] = hdir + 10;
			hx = nx;
			hy = ny;

			// move tail
			if (nv != 1)
			{
				int tdir = map[tx][ty] - 10;
				int ntx = tx + dx[tdir];
				int nty = ty + dy[tdir];
				map[tx][ty] = 0;
				tx = ntx;
				ty = nty;
			}

			// rotate
			if (cmd[t] > 0)
			{
				if (cmd[t] == 'L')
				{
					hdir = (hdir + 4 - 1) % 4;
					map[hx][hy] = hdir + 10;
				}
				else if (cmd[t] == 'D')
				{
					hdir = (hdir + 1) % 4;
					map[hx][hy] = hdir + 10;
				}
			}

			++t;
		}

		cout << t;
		return 0;
	}
};