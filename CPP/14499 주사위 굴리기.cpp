// https://www.acmicpc.net/problem/14499

#include <bits/stdc++.h>
using namespace std;

struct p14499
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		deque<int> dr(4, 0);
		deque<int> dc(4, 0);
		int n, m, x, y, k;
		int g[20][20];
		cin >> n >> m >> x >> y >> k;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> g[i][j];
			}
		}

		const int dx[]{ 0, 0, 0, -1, 1 };
		const int dy[]{ 0, 1, -1, 0, 0 };
		deque<int>* const src[]{ 0, &dc, &dc, &dr, &dr };
		deque<int>* const dst[]{ 0, &dr, &dr, &dc, &dc };
		const char dir[]{ 0, 'R', 'L', 'L', 'R' };

		while (k--)
		{
			int op;
			cin >> op;
			int nx = x + dx[op];
			int ny = y + dy[op];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			x = nx; y = ny;
			deque<int>& s = *src[op];
			deque<int>& d = *dst[op];

			if (dir[op] == 'R')
			{
				s.push_back(s.front());
				s.pop_front();
			}
			else if (dir[op] == 'L')
			{
				s.push_front(s.back());
				s.pop_back();
			}

			if (g[x][y] == 0)
			{
				g[x][y] = s[2];
			}
			else if (g[x][y] != 0)
			{
				s[2] = g[x][y];
				g[x][y] = 0;
			}

			d[0] = s[0];
			d[2] = s[2];
			cout << s[0] << "\n";
		}

		return 0;
	}
};