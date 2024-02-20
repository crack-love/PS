// https://www.acmicpc.net/problem/1337

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1337
{
	int main()
	{
		fastio;

		int n;
		cin >> n;
		if (n == 0)
		{
			cout << 5;
			return 0;
		}

		vector a(n, 0);
		for1(i, n)
		{
			cin >> a[i];
		}
		sort(all(a));

		int l = 0, r = 0;
		int ans = 5;
		int add = 0;
		int ran = 0;
		while (true)
		{
			if (ran <= 4)
			{
				ans = min(ans, add + (4 - ran));

				if (r + 1 >= n)
					break;

				int diff = a[r + 1] - a[r];
				add += diff - 1;
				ran += diff;
				r += 1;
			}
			else
			{
				int diff = a[l + 1] - a[l];
				add -= diff - 1;
				ran -= diff;
				l += 1;
			}
		}

		cout << ans;
		return 0;
	}
};