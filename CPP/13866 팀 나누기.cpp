// https://www.acmicpc.net/problem/13866

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p13866
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[4];
		int s = 0;
		for1(i, 4)
		{
			cin >> a[i];
			s += a[i];
		}

		int ans = INT_MAX;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = i + 1; j < 4; ++j)
			{
				int other = s - a[i] - a[j];
				ans = min(ans, abs(a[i] + a[j] - other));
			}
		}

		cout << ans;
		return 0;
	}
};