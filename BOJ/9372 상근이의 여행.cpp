// https://www.acmicpc.net/problem/9372

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9372
{
	int main()
	{
		int t;
		cin >> t;
		while (t--)
		{
			int n, m;
			cin >> n >> m;
			for (int i = 0; i < m; ++i)
			{
				int a, b;
				cin >> a >> b;
			}
			cout << n - 1 << "\n";
		}
	}
};