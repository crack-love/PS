// https://www.acmicpc.net/problem/2845

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2845
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int l, p;
		cin >> l >> p;

		for (int i = 0; i < 5; ++i)
		{
			int x;
			cin >> x;
			cout << x - (l * p) << " ";
		}

		return 0;
	}
};