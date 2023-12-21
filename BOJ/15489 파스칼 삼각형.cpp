// https://www.acmicpc.net/problem/15489

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p15489
{
	int main()
	{
		fastio;

		int r, c, w;
		cin >> r >> c >> w;
		r -= 1;
		c -= 1;
		int g[30][30]{};
		fill(&g[0][0], &g[29][30], 1);
		for (int i = 2; i < 30; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				g[i][j] = g[i - 1][j - 1] + g[i - 1][j];
			}
		}

		int jsize = 1;
		int sum = 0;
		for (int i = r; i < r + w; ++i)
		{
			for (int j = c; j < c + jsize; ++j)
			{
				sum += g[i][j];
			}
			jsize += 1;
		}

		cout << sum;
		return 0;
	}
};