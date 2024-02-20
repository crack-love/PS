// https://www.acmicpc.net/problem/2979

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p2979
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b, c;
		cin >> a >> b >> c;

		int t[101]{};
		for1(i, 3)
		{
			int s, e;
			cin >> s >> e;
			t[s] += 1;
			t[e] -= 1;
		}

		int ans = 0;
		int cnt = 0;
		for (int i = 0; i < 101; ++i)
		{
			cnt += t[i];
			if (cnt >= 3)
			{
				ans += c * cnt;
			}
			else if (cnt >= 2)
			{
				ans += b * cnt;
			}
			else if (cnt >= 1)
			{
				ans += a * cnt;
			}
		}

		cout << ans;
		return 0;
	}
};