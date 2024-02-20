// https://www.acmicpc.net/problem/15486

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p15486
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		// d[i+t] = max(d[i]+pi, d[i+t])
		// d[i+(1~t-1)] = max(that, d[i])

		int n;
		const int SIZE = 1'500'000 + 1;
		int t[SIZE];
		int p[SIZE];
		int d[SIZE]{};
		cin >> n;
		for1(i, n)
		{
			cin >> t[i] >> p[i];
		}

		for1(i, n)
		{
			if (i + t[i] <= n)
			{
				d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
			}

			for (int j = 1; j < t[i] && i + j <= n; ++j)
			{
				d[i + j] = max(d[i + j], d[i]);
			}
		}

		cout << d[n];
		return 0;
	}
};