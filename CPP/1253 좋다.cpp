// https://www.acmicpc.net/problem/1253

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1253
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int a[2000]{};
		for1(i, n)
		{
			cin >> a[i];
		}
		sort(a, a + n);

		int ans = 0;
		for1(i, n)
		{
			int l = 0, r = n - 1;
			while (l < r)
			{
				if (l == i)
				{
					l += 1;
					continue;
				}
				else if (r == i)
				{
					r -= 1;
					continue;
				}

				int s = a[l] + a[r];
				if (s < a[i])
				{
					l += 1;
				}
				else if (s > a[i])
				{
					r -= 1;
				}
				else
				{
					ans += 1;
					break;
				}
			}
		}

		cout << ans;
		return 0;
	}
};