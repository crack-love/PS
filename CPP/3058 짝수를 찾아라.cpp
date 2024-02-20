// https://www.acmicpc.net/problem/3058

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p3058
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int sum = 0;
			int minv = INT_MAX;
			for1(i, 7)
			{
				int x;
				cin >> x;
				if (x % 2 == 0)
				{
					sum += x;
					minv = min(minv, x);
				}
			}

			cout << sum << " " << minv << "\n";
		}

		return 0;
	}
};