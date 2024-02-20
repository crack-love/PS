// https://www.acmicpc.net/problem/10214

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p10214
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int as = 0;
			int bs = 0;
			for1(i, 9)
			{
				int x, y;
				cin >> x >> y;
				as += x;
				bs += y;
			}

			if (as > bs)
				cout << "Yonsei";
			else if (bs > as)
				cout << "Korea";
			else
				cout << "Draw";
			cout << "\n";
		}

		return 0;
	}
};