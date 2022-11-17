// https://www.acmicpc.net/problem/2636

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2636
{
	int r, c;
	int a[100][100];
	vector<int> answer;
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };
	bool bfs()
	{
		int cnt = 0;
		for2(i, j, r, c)
		{
			if (a[i][j] == 1)
			{
				cnt += 1;
			}
			else if (a[i][j] == 2)
			{
				a[i][j] = 0;
			}
		}
		answer.push_back(cnt);

		if (cnt > 0)
		{
			bool visited[100][100]{};
			queue<pair<int, int>> q;
			q.push({ 0,0 });
			visited[0][0] = true;
			while (!q.empty())
			{
				auto [x, y] = q.front();
				q.pop();

				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					step(nx, ny, r, c);
					if (visited[nx][ny]) continue;
					visited[nx][ny] = true;
					if (a[nx][ny] == 1)
					{
						a[nx][ny] = 2;
					}
					else
					{
						q.push({ nx,ny });
					}
				}
			}
		}

		return cnt > 0;
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

		while (bfs())
		{
		}

		if (answer.size() >= 2)
		{
			cout << answer.size() - 1 << "\n";
			cout << answer[answer.size() - 2];
		}
		else
		{
			cout << 0 << "\n";
			cout << 0;
		}

		return 0;
	}
};