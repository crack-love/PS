// https://www.acmicpc.net/problem/13458

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p13458
{
	int main()
	{
		int n;
		int a[(int)1e6];
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		int b, c; // รั,บฮ
		cin >> b >> c;

		long long ans = n;
		for (int i = 0; i < n; ++i)
		{
			a[i] -= b;
			if (a[i] > 0)
			{
				ans += (long long)ceil(a[i] / (double)c);
			}
		}

		cout << ans;
		return 0;
	}
};