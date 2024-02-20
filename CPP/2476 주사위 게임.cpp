// https://www.acmicpc.net/problem/2476

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2476
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int ans = 0;
		for1(i, n)
		{
			int x, y, z;
			cin >> x >> y >> z;

			int v = 0;
			if (x == y && y == z)
			{
				v = 10000 + x * 1000;
			}
			else if (x == y || x == z)
			{
				v = 1000 + x * 100;
			}
			else if (y == z)
			{
				v = 1000 + y * 100;
			}
			else
			{
				v = max(x, max(y, z)) * 100;
			}
			ans = max(ans, v);
		}
		cout << ans;
		return 0;
	}
};