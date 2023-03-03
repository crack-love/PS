// https://www.acmicpc.net/problem/2566

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2566
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int v = 0;
		int x = 0;
		int y = 0;
		for2(i, j, 9, 9)
		{
			int val;
			cin >> val;
			if (val > v)
			{
				v = val;
				x = i;
				y = j;
			}
		}

		cout << v << "\n" << x + 1 << " " << y + 1;

		return 0;
	}
};