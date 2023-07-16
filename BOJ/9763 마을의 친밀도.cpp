// https://www.acmicpc.net/problem/9763

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p9763
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		tuple<int, int, int> p[10000]{};
		int n;
		cin >> n;
		for1(i, n)
		{
			int x, y, z;
			cin >> x >> y >> z;
			p[i] = { x,y,z };
		}

		int ans = INT_MAX;
		for1(i, n)
		{
			auto [ix, iy, iz] = p[i];

			int mind1 = INT_MAX;
			int mind2 = INT_MAX;
			for1(j, n)
			{
				if (i == j) continue;

				auto [jx, jy, jz] = p[j];
				int d = abs(ix - jx) + abs(iy - jy) + abs(iz - jz);
				if (d < mind1)
				{
					mind2 = mind1;
					mind1 = d;
				}
				else if (d < mind2)
				{
					mind2 = d;
				}
			}

			ans = min(ans, mind1 + mind2);
		}

		cout << ans;
		return 0;
	}
};