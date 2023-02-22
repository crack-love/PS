// https://www.acmicpc.net/problem/9325

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9325
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int s, n;
			cin >> s >> n;
			for1(i, n)
			{
				int q, p;
				cin >> q >> p;
				s += q * p;
			}
			cout << s << "\n";
		}

		return 0;
	}
};