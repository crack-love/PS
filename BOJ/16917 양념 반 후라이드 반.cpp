// https://www.acmicpc.net/problem/16917

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p16917
{
	int main()
	{
		fastio;

		int a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;

		int ans = 0;
		if (a + b > c * 2)
		{
			int m = min(x, y);
			x -= m;
			y -= m;
			ans += m * c * 2;
		}

		if (x > 0)
		{
			if (a > c * 2)
			{
				ans += x * c * 2;
				y -= x;
			}
			else
			{
				ans += x * a;
			}
		}
		if (y > 0)
		{
			if (b > c * 2)
			{
				ans += y * c * 2;
				x -= y;
			}
			else
			{
				ans += y * b;
			}
		}

		cout << ans;

		return 0;
	}
};