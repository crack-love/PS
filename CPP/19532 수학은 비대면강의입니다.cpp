// https://www.acmicpc.net/problem/19532

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p19532
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;

		for (int i = -999; i < 1000; ++i)
		{
			for (int j = -999; j < 1000; ++j)
			{
				if (a * i + b * j == c &&
					d * i + e * j == f)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
};