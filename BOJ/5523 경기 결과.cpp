// https://www.acmicpc.net/problem/5523

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5523
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a = 0, b = 0;
		int n;
		cin >> n;
		while (n--)
		{
			int x, y;
			cin >> x >> y;
			if (x > y)
				a += 1;
			else if (y > x)
				b += 1;
		}

		cout << a << " " << b;

		return 0;
	}
};