// https://www.acmicpc.net/problem/20040

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p20040_union
{
	int n, m;
	int p[(int)5e5]{};

	int getPar(int x)
	{
		if (p[x] == -1)
		{
			return p[x] = x;
		}
		else if (p[x] != x)
		{
			return p[x] = getPar(p[x]);
		}
		else
		{
			return x;
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		//freopen("20040 in2.txt", "r", stdin);

		cin >> n >> m;

		memset(p, -1, sizeof(p));
		for1(i, m)
		{
			int a, b;
			cin >> a >> b;

			int ap = getPar(a);
			int bp = getPar(b);

			if (ap == bp)
			{
				cout << i + 1;
				return 0;
			}
			else
			{
				p[bp] = ap;
			}
		}

		cout << 0;
		return 0;
	}
};