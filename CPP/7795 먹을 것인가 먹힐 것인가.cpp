// https://www.acmicpc.net/problem/7795

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p7795
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n, m;
			cin >> n >> m;
			int a[20000];
			int b[20000];
			for1(i, n)
			{
				cin >> a[i];
			}
			for1(i, m)
			{
				cin >> b[i];
			}

			sort(b, b + m);

			int ans = 0;
			for1(i, n)
			{
				auto it = lower_bound(b, b + m, a[i]);
				int idx = it - b;
				ans += idx;
			}

			cout << ans << "\n";
		}

		return 0;
	}
};