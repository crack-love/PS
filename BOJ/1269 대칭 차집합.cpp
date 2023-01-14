// https://www.acmicpc.net/problem/1269

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1269
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[(int)2e5], b[(int)2e5];
		int n, m;
		cin >> n >> m;
		for1(i, n)
		{
			cin >> a[i];
		}
		for1(i, m)
		{
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + m);

		int cnt = 0;
		int ai = 0, bi = 0;
		while (ai < n && bi < m)
		{
			if (a[ai] == b[bi])
			{
				ai += 1;
				bi += 1;
				cnt += 1;
			}
			else if (a[ai] < b[bi])
			{
				ai += 1;
			}
			else
			{
				bi += 1;
			}
		}
		cout << n + m - cnt * 2;

		return 0;
	}

};