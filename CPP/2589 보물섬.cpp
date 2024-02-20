// https://www.acmicpc.net/problem/2589

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2589
{
	int r, c;
	char a[50][50];
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	int answer = 0;
	void bfs(int bx, int by)
	{
		bool visited[50][50]{};
		deque<tuple<int, int, int>> dq;
		dq.push_back({ bx,by,0 });
		visited[bx][by] = 1;
		while (!dq.empty())
		{
			auto [x, y, cnt] = dq.front();
			dq.pop_front();
			if (cnt > answer) answer = cnt;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				step(nx, ny, r, c);
				if (a[nx][ny] == 'W') continue;
				if (visited[nx][ny]) continue;
				dq.push_back({ nx,ny,cnt + 1 });
				visited[nx][ny] = 1;
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> r >> c;
		for2(i, j, r, c)
		{
			cin >> a[i][j];
		}

		for2(i, j, r, c)
		{
			if (a[i][j] == 'L')
			{
				bfs(i, j);
			}
		}
		cout << answer;
		return 0;
	}
};