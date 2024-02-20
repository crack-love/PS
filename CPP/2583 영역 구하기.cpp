// https://www.acmicpc.net/problem/2583

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2583
{
	int g[101][101];
	int n, m;
	const int dx[4] = { 0, 0, 1, -1 };
	const int dy[4] = { 1, -1, 0, 0 };

	int dfs(int x, int y)
	{
		g[x][y] = 1;
		int cnt = 1;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			step(nx, ny, m, n);
			if (g[nx][ny]) continue;

			cnt += dfs(nx, ny);
		}
		return cnt;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int k;
		cin >> m >> n >> k;
		for (int i = 0; i < k; ++i)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			for2(u, v, c - a, d - b)
			{
				g[b + v][a + u] = 1;
			}
		}

		vector<int> ans;
		for2(i, j, m, n)
		{
			if (g[i][j] == 0)
			{
				ans.push_back(dfs(i, j));
			}
		}

		sort(ans.begin(), ans.end());
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i] << " ";
		}

		return 0;
	}
};