// https://www.acmicpc.net/problem/2018

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2018
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int s = 0;
		int ans = 0;
		int beg = 0;
		int end = 1;
		while (beg <= n)
		{
			if (s < n)
			{
				s += end++;
			}
			else if (s > n)
			{
				s -= beg++;
			}
			else
			{
				ans += 1;
				s += end++;
			}
		}

		cout << ans;

		return 0;
	}
};