// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
using namespace std;
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)

struct p2573
{
	int n, m;
	int g[300][300];
	const int dx[4]{ 0, 0,1,-1 };
	const int dy[4]{ 1,-1,0,0 };
	bool visited[300][300]{};

	int getGroup()
	{
		memset(visited, 0, sizeof(visited));

		vector<pair<int, int>> s;
		int gcnt = 0;
		for2(i, j, n, m)
		{
			if (visited[i][j]) continue;
			if (g[i][j] > 0)
			{
				s.push_back({ i,j });
				++gcnt;
				visited[i][j] = true;

				while (s.size() > 0)
				{
					auto [x, y] = s.back();
					s.pop_back();

					for1(k, 4)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (visited[nx][ny]) continue;
						if (g[nx][ny] == 0) continue;

						visited[nx][ny] = true;
						s.push_back({ nx,ny });
					}
				}
			}
		}
		return gcnt;
	}

	void carv()
	{
		memset(visited, 0, sizeof(visited));

		for2(i, j, n, m)
		{
			if (g[i][j] == 0 && !visited[i][j])
			{
				for1(k, 4)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (g[nx][ny] > 0)
					{
						visited[nx][ny] = true;
						g[nx][ny] = max(g[nx][ny] - 1, 0);
					}
				}
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		cin >> n >> m;
		for2(i, j, n, m)
		{
			cin >> g[i][j];
		}

		int y = 0;
		while (true)
		{
			int gc = getGroup();
			if (gc >= 2)
			{
				cout << y;
				break;
			}
			else if (gc == 0)
			{
				cout << 0;
				break;
			}

			carv();
			++y;
		}

		return 0;
	}
};