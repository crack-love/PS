// https://www.acmicpc.net/problem/10797

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10797
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int d;
		int ans = 0;
		cin >> d;
		for (int i = 0; i < 5; ++i)
		{
			int x;
			cin >> x;
			if (x % 10 == d)
			{
				ans += 1;
			}
		}
		cout << ans;

		return 0;
	}
};