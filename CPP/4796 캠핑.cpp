// https://www.acmicpc.net/problem/5639

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p4796
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int tc = 0;
		while (++tc)
		{
			int l, p, v;
			cin >> l >> p >> v;
			if (l == 0 && p == 0 && v == 0)
			{
				break;
			}

			int r = (v / p) * l;
			v %= p;
			if (v >= l)
			{
				r += l;
			}
			else
			{
				r += v;
			}
			cout << "Case " << tc << ": " << r << "\n";
		}


		return 0;
	}
};