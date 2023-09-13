// https://www.acmicpc.net/problem/2033

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2033
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;

		int lv = 10;
		while (n > lv)
		{
			int f = n % lv;

			if (f >= 5 * (lv / 10))
			{
				n += lv;
				n -= f;
			}
			else
			{
				n -= f;
			}

			lv *= 10;
		}

		cout << n;
		return 0;
	}
};