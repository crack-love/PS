// https://www.acmicpc.net/problem/1531

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1531
{
	int main()
	{
		fastio;

		int n, m;
		cin >> n >> m;
		int g[101][101]{};
		int cnt = 0;
		for1(i, n)
		{
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			for (int x = x0; x <= x1; ++x)
				for (int y = y0; y <= y1; ++y)
				{
					g[x][y] += 1;
					if (g[x][y] == m + 1)
						cnt += 1;
				}
		}

		cout << cnt;

		return 0;
	}
};