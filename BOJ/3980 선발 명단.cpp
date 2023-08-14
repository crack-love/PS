// https://www.acmicpc.net/problem/3980

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p3980
{
	int ans = 0;
	void solve(int i, int sum, int used, vector<pair<int, int>> s[])
	{
		if (i >= 11)
		{
			ans = max(sum, ans);
			return;
		}

		for1(j, s[i].size())
		{
			auto [p, v] = s[i][j];
			if (used & (1 << p)) continue;

			solve(i + 1, sum + v, used | (1 << p), s);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int c;
		cin >> c;
		while (c--)
		{
			ans = 0;
			vector<pair<int, int>> s[11];

			for2(i, j, 11, 11)
			{
				int x;
				cin >> x;
				if (x > 0)
				{
					s[i].push_back({ j,x });
				}
			}

			solve(0, 0, 0, s);
			cout << ans << "\n";
		}

		return 0;
	}
};