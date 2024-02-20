// https://www.acmicpc.net/problem/5639

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1547
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int m;
		cin >> m;
		int a[3]{ 1,0,0 };
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			cin >> x >> y;
			swap(a[x - 1], a[y - 1]);
		}
		for (int i = 0; i < 3; ++i)
		{
			if (a[i])
			{
				cout << i + 1;
				return 0;
			}
		}
		cout << -1;
		return 0;
	}
};