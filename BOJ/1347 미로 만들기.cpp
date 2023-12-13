// https://www.acmicpc.net/problem/1347

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x, y) begin(x),end(y)
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1347
{
	int main()
	{
		fastio;

		char g[200][200]{};
		int x = 100;
		int y = 100;
		pair<int, int> xrange = { x,x };
		pair<int, int> yrange = { y,y };
		fill(all(g[0], g[199]), '#');
		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,-1,0,1 };
		int dir = 0;
		g[x][y] = '.';

		int n;
		cin >> n;
		for1(i, n)
		{
			char c;
			cin >> c;

			if (c == 'R')
			{
				dir = (dir + 1) % 4;
			}
			else if (c == 'L')
			{
				dir = (dir - 1 + 4) % 4;
			}
			else if (c == 'F')
			{
				x = x + dx[dir];
				y = y + dy[dir];
				g[x][y] = '.';
				auto& [xb, xe] = xrange;
				auto& [yb, ye] = yrange;
				xb = min(xb, x);
				xe = max(xe, x);
				yb = min(yb, y);
				ye = max(ye, y);
			}
		}

		for (int i = xrange.first; i <= xrange.second; ++i)
		{
			for (int j = yrange.first; j <= yrange.second; ++j)
			{
				cout << g[i][j];
			}
			cout << "\n";
		}

		return 0;
	}
};