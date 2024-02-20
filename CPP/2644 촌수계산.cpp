// https://www.acmicpc.net/problem/2644

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2644
{
	int par[101];
	vector<int> child[101];
	int visited[101];
	int answer;

	void dfs(int x, int f, int c)
	{
		if (visited[x] <= c)
		{
			return;
		}
		else if (x == f)
		{
			answer = min(answer, c);
			return;
		}
		else
		{
			visited[x] = c;
		}

		if (par[x] != 0)
		{
			dfs(par[x], f, c + 1);
		}
		for (int i = 0; i < child[x].size(); ++i)
		{
			dfs(child[x][i], f, c + 1);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, a, b, m;
		cin >> n >> a >> b >> m;

		while (m--)
		{
			int x, y;
			cin >> x >> y;
			par[y] = x;
			child[x].push_back(y);
		}

		fill(visited, visited + n + 1, 1000);
		answer = 1000;

		dfs(a, b, 0);

		if (answer == 1000)
		{
			cout << -1;
		}
		else
		{
			cout << answer;
		}

		return 0;
	}
};