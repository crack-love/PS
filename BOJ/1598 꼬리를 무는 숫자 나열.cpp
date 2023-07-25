// https://www.acmicpc.net/problem/1598

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1598
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		auto getXY = [](int v)->pair<int, int>
		{
			int x = (v - 1) / 4;
			int y = (v - 1) % 4;
			return { x,y };
		};

		int a, b;
		cin >> a >> b;
		auto [x1, y1] = getXY(a);
		auto [x2, y2] = getXY(b);

		int ans = abs(x2 - x1) + abs(y2 - y1);
		cout << ans;

		return 0;
	}
};