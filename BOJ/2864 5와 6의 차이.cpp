// https://www.acmicpc.net/problem/2864

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2864
{
	int change(int x, int src, int dst)
	{
		int res = 0;
		int lv = 1;
		while (x > 0)
		{
			int v = x % 10;
			if (v == src)
			{
				res += dst * lv;
			}
			else
			{
				res += v * lv;
			}
			x /= 10;
			lv *= 10;
		}
		return res;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b;
		cin >> a >> b;

		cout << change(a, 6, 5) + change(b, 6, 5) << " ";
		cout << change(a, 5, 6) + change(b, 5, 6);

		return 0;
	}
};