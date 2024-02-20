// https://www.acmicpc.net/problem/2851

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2851
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[10];
		int ans = 0;
		int s = 0;
		int mindiff = 100000;

		for1(i, 10)
		{
			cin >> a[i];

			s += a[i];
			int diff = abs(s - 100);
			if (diff <= mindiff)
			{
				ans = s;
				mindiff = diff;
			}
		}

		cout << ans;

		return 0;
	}
};