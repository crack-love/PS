// https://www.acmicpc.net/problem/1940

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1940
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		int a[15000];

		for1(i, n)
		{
			cin >> a[i];
		}

		sort(a, a + n);
		int b = 0, e = n;
		int ans = 0;

		while (b < e - 1)
		{
			int s = a[b] + a[e - 1];
			if (s == m)
			{
				b += 1;
				ans += 1;
			}
			else if (s > m)
			{
				e -= 1;
			}
			else
			{
				b += 1;
			}
		}

		cout << ans;

		return 0;
	}
};