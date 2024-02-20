// https://www.acmicpc.net/problem/2738

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2738
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[100][100];
		int n, m;
		cin >> n >> m;
		for2(i, j, n, m)
		{
			cin >> a[i][j];
		}
		for2(i, j, n, m)
		{
			int x;
			cin >> x;
			a[i][j] += x;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}

		return 0;
	}
};