// https://www.acmicpc.net/problem/17362

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p17362
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		n -= 1;
		int v = n % 8;
		if (v > 4)
		{
			// 5 6 7 -> 3 2 1
			v = 8 - v;
		}
		cout << v + 1;

		return 0;
	}
};