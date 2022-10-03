// https://www.acmicpc.net/problem/2576

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2576
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int minval = 101;
		int sum = 0;
		for (int i = 0; i < 7; ++i)
		{
			int x;
			cin >> x;
			if (x % 2 == 1)
			{
				minval = min(x, minval);
				sum += x;
			}
		}

		if (minval == 101)
		{
			cout << -1;
		}
		else
		{
			cout << sum << "\n";
			cout << minval << "\n";
		}

		return 0;
	}
};