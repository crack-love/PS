// https://www.acmicpc.net/problem/2668

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2668
{
	int n;
	int a[101];
	bool visited[101]{};
	bool visitedPick[101]{};
	bool picked[101]{};

	void dfsPick(int x)
	{
		visitedPick[x] = true;
		picked[x] = true;

		int nx = a[x];
		if (!visitedPick[nx])
		{
			dfsPick(nx);
		}
	}

	void dfs(int x)
	{
		visited[x] = true;

		int nx = a[x];
		if (visited[nx])
		{
			if (!picked[nx])
			{
				memset(visitedPick, 0, sizeof(visitedPick));
				dfsPick(nx);
			}
		}
		else
		{
			dfs(nx);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}


		for (int i = 1; i <= n; ++i)
		{
			memset(visited, 0, sizeof(visited));
			dfs(i);
		}

		vector<int> v;
		for (int i = 1; i <= n; ++i)
		{
			if (picked[i])
				v.push_back(i);
		}
		sort(v.begin(), v.end());

		cout << v.size() << "\n";
		for (int i : v)
		{
			cout << i << "\n";
		}

		return 0;
	}
};