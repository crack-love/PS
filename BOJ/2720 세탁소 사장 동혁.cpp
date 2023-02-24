// https://www.acmicpc.net/problem/2720

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2720
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int c;
			cin >> c;

			int q = c / 25;
			c %= 25;
			int d = c / 10;
			c %= 10;
			int n = c / 5;
			c %= 5;
			int p = c;
			cout << q << " " << d << " " << n << " " << p << "\n";
		}

		return 0;
	}
};