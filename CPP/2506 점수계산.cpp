// https://www.acmicpc.net/problem/2506

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2506
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int ans = 0;
		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			if (x == 0)
			{
				j = 0;
			}
			else if (x == 1)
			{
				j += 1;
				ans += j;
			}
		}
		cout << ans;
		return 0;
	}
};