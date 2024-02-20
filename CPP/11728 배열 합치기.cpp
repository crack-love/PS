// https://www.acmicpc.net/problem/11728

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p11728
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		const int size = (int)1e6 + 1;
		int a[size];
		int b[size];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}

		a[n] = (int)1e9 + 1;
		b[m] = (int)1e9 + 1;
		sort(a, a + n);
		sort(b, b + m);
		int ai = 0;
		int bi = 0;
		while (ai + bi < n + m)
		{
			if (a[ai] <= b[bi])
			{
				cout << a[ai] << " ";
				ai += 1;
			}
			else
			{
				cout << b[bi] << " ";
				bi += 1;
			}
		}

		return 0;
	}
};