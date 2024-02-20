// https://www.acmicpc.net/problem/14470

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p14470
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int d, ed;
		cin >> d >> ed;
		int t0, t1, t2;
		cin >> t0 >> t1 >> t2;

		int ans = 0;
		if (d < 0)
		{
			ans += -d * t0;
			d = 0;
		}
		if (d == 0)
		{
			ans += t1;
		}
		ans += (ed - d) * t2;

		cout << ans;
		return 0;
	}
};