// https://www.acmicpc.net/problem/2628

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p2628
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int g[2][101]{};

		int size[2];
		cin >> size[1] >> size[0];
		int n;
		cin >> n;
		for1(i, n)
		{
			int o, p;
			cin >> o >> p;
			g[o][p] = 1;
		}

		int maxs[2]{};
		for1(i, 2)
		{
			int lastpos = 0;

			for1(j, size[i] + 1)
			{
				maxs[i] = max(maxs[i], j - lastpos);

				if (g[i][j] == 1)
					lastpos = j;
			}
		}

		cout << maxs[0] * maxs[1];
		return 0;
	}
};