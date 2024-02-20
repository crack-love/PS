// https://www.acmicpc.net/problem/1568

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p1568
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int i = 1;
		int ans = 0;
		while (n > 0)
		{
			n -= i;
			ans += 1;
			i += 1;
			if (i > n)
				i = 1;
		}
		cout << ans;

		return 0;
	}
};