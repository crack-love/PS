// https://www.acmicpc.net/problem/14719

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p14719
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int h, w;
		cin >> h >> w;

		int a[500];
		for1(i, w)
		{
			cin >> a[i];
		}

		int ans = 0;
		for (int i = 1; i <= h; ++i)
		{
			int left = -1;
			for (int j = 0; j < w; ++j)
			{
				if (a[j] >= i)
				{
					if (left != -1)
					{
						ans += j - left - 1;
					}
					left = j;
				}
			}
		}

		cout << ans;
		return 0;
	}
};