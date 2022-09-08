// https://www.acmicpc.net/problem/7562

#include <bits/stdc++.h>
using namespace std;
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)

struct p7562
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		const int d[][2]{ {-2, 1},{-1,2}, {1,2}, {2,1}, {2, -1}, {1, -2}, {-1,-2}, {-2,-1} };
		bool visited[300][300];
		int t;
		cin >> t;
		while (t--)
		{
			int n, bx, by, ex, ey;
			cin >> n >> bx >> by >> ex >> ey;

			memset(visited, 0, sizeof(visited));
			queue<tuple<int, int, int>> q;
			q.push({ bx, by, 0 });
			visited[bx][by] = true;
			while (!q.empty())
			{
				auto [x, y, c] = q.front();
				q.pop();

				if (x == ex && y == ey)
				{
					cout << c << "\n";
					break;
				}

				for (int i = 0; i < 8; ++i)
				{
					int nx = x + d[i][0];
					int ny = y + d[i][1];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (visited[nx][ny]) continue;

					visited[nx][ny] = true;
					q.push({ nx,ny,c + 1 });
				}
			}
		}

		return 0;
	};
};
