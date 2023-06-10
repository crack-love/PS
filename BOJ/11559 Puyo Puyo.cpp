// https://www.acmicpc.net/problem/11559

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p11559
{
	static const int SX = 12;
	static const int SY = 6;
	char a[SX][SY];
	bool visited[SX][SY];
	vector<pair<int, int>> lastDfs;

	void dfs(int x, int y)
	{
		visited[x][y] = true;
		char c = a[x][y];
		lastDfs.push_back({ x,y });

		for1(i, 4)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			step(nx, ny, SX, SY);
			if (visited[nx][ny]) continue;

			if (a[nx][ny] == c)
			{
				dfs(nx, ny);
			}
		}
	}

	void moveDown(int x, int y)
	{
		while (x < SX - 1)
		{
			if (a[x + 1][y] == '.')
			{
				a[x + 1][y] = a[x][y];
				a[x][y] = '.';
				x += 1;
			}
			else
			{
				break;
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		for2(i, j, SX, SY)
		{
			cin >> a[i][j];
		}

		int streakCnt = 0;
		bool streak = true;
		while (streak)
		{
			streak = false;
			memset(visited, 0, sizeof(visited));

			for2(i, j, SX, SY)
			{
				if (!visited[i][j] && a[i][j] != '.')
				{
					lastDfs.clear();
					dfs(i, j);

					if (lastDfs.size() >= 4)
					{
						streak |= true;
						for (auto [x, y] : lastDfs)
						{
							a[x][y] = '.';
						}
					}
				}
			}

			if (streak)
			{
				streakCnt += 1;

				for (int i = SX - 2; i >= 0; --i)
				{
					for1(j, SY)
					{
						moveDown(i, j);
					}
				}
			}
		}

		cout << streakCnt;

		return 0;
	}
};