// https://www.acmicpc.net/problem/2501

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2501
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
		{
			if (n % i == 0)
			{
				--k;
				if (k == 0)
				{
					cout << i;
					return 0;
				}
			}
		}
		cout << 0;
		return 0;
	}
};