// https://www.acmicpc.net/problem/2921

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p2921
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		// 00 = 0
		// 10 11 = 1*2+(1)
		// 20 21 22 = 2*3+(1+2)
		// 30 31 32 33 = 3*4+(1+2+3)

		int n;
		cin >> n;

		// s0~n(i*(i+1)+s0~i(j))
		long long ans = 0;
		for1(i, n + 1)
		{
			ans += i * (long long)(i + 1);

			for1(j, i + 1)
			{
				ans += j;
			}
		}
		cout << ans;

		return 0;
	}
};