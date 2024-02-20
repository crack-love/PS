// https://www.acmicpc.net/problem/2953

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2953
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[5]{};
		int ans = 0;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				int x;
				cin >> x;
				a[i] += x;
			}

			if (a[i] > a[ans])
			{
				ans = i;
			}
		}

		cout << ans + 1 << " " << a[ans];

		return 0;
	}
};