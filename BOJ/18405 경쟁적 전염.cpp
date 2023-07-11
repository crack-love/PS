// https://www.acmicpc.net/problem/18405

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p18405
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		int g[200][200]{};
		cin >> n >> k;
		for2(i, j, n, n)
		{
			cin >> g[i][j];
		}

		int s, x, y;
		cin >> s >> x >> y;
		x -= 1; y -= 1;
		queue<tuple<int, int, int>>q;
		q.push({ x,y,0 });
		int ansT = INT_MAX;
		int ansV = INT_MAX;
		while (q.size() > 0)
		{
			auto [x, y, t] = q.front(); q.pop();

			if (t > ansT)
				break;

			if (g[x][y] != 0)
			{
				ansT = t;
				ansV = min(ansV, g[x][y]);
			}

			if (t < s)
			{
				for1(k, 4)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					step(nx, ny, n, n);
					q.push({ nx,ny,t + 1 });
				}
			}
		}

		cout << (ansV == INT_MAX ? 0 : ansV);

		return 0;
	}
};