// https://www.acmicpc.net/problem/2637

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2637
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		vector<int> next[101];
		vector<pair<int, int>> prev[101];
		int pcnt[101]{};

		for1(i, m)
		{
			int x, y, k;
			cin >> x >> y >> k;

			next[y].push_back(x);
			prev[x].push_back({ y,k });
			pcnt[x] += 1;
		}

		queue<int> q;
		int dp[101][101]{};
		for (int i = 1; i <= n; ++i)
		{
			if (pcnt[i] == 0)
			{
				q.push(i);
				dp[i][i] = 1;
			}
		}

		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();

			for (auto [px, pc] : prev[x])
			{
				for (int i = 1; i <= n; ++i)
				{
					dp[x][i] += dp[px][i] * pc;
				}
			}

			for (auto nx : next[x])
			{
				pcnt[nx] -= 1;
				if (pcnt[nx] == 0)
				{
					q.push(nx);
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			if (prev[i].size() <= 0)
			{
				cout << i << " " << dp[n][i] << "\n";
			}
		}

		return 0;
	}
};