// https://www.acmicpc.net/problem/9063

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p9063
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int x0 = INT_MAX, x1 = INT_MIN, y0 = INT_MAX, y1 = INT_MIN;

		for1(i, n)
		{
			int x, y;
			cin >> x >> y;

			x0 = min(x, x0);
			y0 = min(y, y0);
			x1 = max(x, x1);
			y1 = max(y, y1);
		}

		cout << (x1 - x0) * (y1 - y0);

		return 0;
	}
};