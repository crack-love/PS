// https://www.acmicpc.net/problem/16967

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p16967
{
	int main()
	{
		fastio;

		int h, w, x, y;
		cin >> h >> w >> x >> y;
		int g[600][600]{};
		for2(i, j, h + x, w + y)
		{
			cin >> g[i][j];
		}

		for (int i = x; i < h; ++i)
			for (int j = y; j < w; ++j)
			{
				g[i][j] = g[i][j] - g[i - x][j - y];
			}

		for2(i, j, h, w)
		{
			cout << g[i][j] << " ";
			if (j == w - 1)
				cout << "\n";
		}

		return 0;
	}
};