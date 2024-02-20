// https://www.acmicpc.net/problem/10807

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10807
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int a[100];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		int v;
		cin >> v;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == v)
			{
				ans += 1;
			}
		}
		cout << ans;

		return 0;
	}
};