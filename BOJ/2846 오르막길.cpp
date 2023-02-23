// https://www.acmicpc.net/problem/2846

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2846
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		int prev;
		int left;
		int ans = 0;
		cin >> n >> prev;
		left = prev;

		for1(i, n - 1)
		{
			int x;
			cin >> x;
			if (prev < x)
			{
				ans = max(ans, x - left);
			}
			else
			{
				left = x;
			}
			prev = x;
		}

		cout << ans;
		return 0;
	}
};