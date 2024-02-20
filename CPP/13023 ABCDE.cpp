// https://www.acmicpc.net/problem/13023

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p13023
{
	int n;
	vector<int> f[2000];
	bool visited[2000];
	bool successed;

	void dfs(int x, int cnt)
	{
		visited[x] = true;
		if (cnt >= 5)
		{
			successed = true;
			return;
		}

		for (int e : f[x])
		{
			if (visited[e]) continue;
			else
			{
				dfs(e, cnt + 1);
				if (successed)
				{
					return;
				}
			}
		}
		visited[x] = false;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int m;
		cin >> n >> m;
		for1(i, m)
		{
			int a, b;
			cin >> a >> b;
			f[a].push_back(b);
			f[b].push_back(a);
		}

		for1(i, n)
		{
			memset(visited, 0, sizeof(visited));

			dfs(i, 1);
			if (successed)
			{
				break;
			}
		}

		cout << successed ? 1 : 0;
		return 0;
	}
};