// https://www.acmicpc.net/problem/2146

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p2146
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int g[100][100];
		int n;
		cin >> n;
		for2(i, j, n, n)
		{
			cin >> g[i][j];
		}

		int grop = 1;
		int ans = 10000;
		for2(u, v, n, n)
		{
			if (g[u][v] != 1) continue;

			grop += 1;

			// fill gruop
			stack<pair<int, int>>fillst;
			queue<tuple<int, int, int>>bfsq;
			g[u][v] = grop;
			fillst.push({ u, v });
			while (fillst.size() > 0)
			{
				auto [x, y] = fillst.top();
				fillst.pop();

				bool isEdge = false;
				for1(i, 4)
				{
					int nx = x + dd[0][i];
					int ny = y + dd[1][i];
					step(nx, ny, n, n);

					if (g[nx][ny] <= 0)
						isEdge = true;

					if (g[nx][ny] == 1)
					{
						g[nx][ny] = grop;
						fillst.push({ nx,ny });
					}
				}

				if (isEdge)
				{
					bfsq.push({ x,y, 0 });
				}
			}

			// bfs edge
			bool bfsEnd = false;
			while (bfsq.size() > 0 && !bfsEnd)
			{
				auto [x, y, c] = bfsq.front();
				bfsq.pop();

				for1(i, 4)
				{
					int nx = x + dd[0][i];
					int ny = y + dd[1][i];
					step(nx, ny, n, n);
					if (g[nx][ny] == -grop) continue;
					if (g[nx][ny] == grop) continue;

					if (g[nx][ny] >= 1)
					{
						ans = min(ans, c);
						bfsEnd = true;
						break;
					}
					else
					{
						g[nx][ny] = -grop;
						bfsq.push({ nx, ny, c + 1 });
					}
				}
			}
		}

		cout << ans;

		return 0;
	}
};