// https://www.acmicpc.net/problem/1068

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1068
{
	int n;
	vector<int> child[50];
	int par[50];
	int answer = 0;

	void dfs(int i)
	{
		if (child[i].size() == 0)
		{
			answer += 1;
			return;
		}

		for (int j : child[i])
		{
			dfs(j);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int root;

		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int p;
			cin >> p;
			if (p == -1)
			{
				root = i;
			}
			else
			{
				child[p].push_back(i);
			}
			par[i] = p;
		}

		int x;
		cin >> x;
		int xp = par[x];
		if (xp == -1)
		{
			cout << 0;
			return 0;
		}
		else
		{
			child[xp].erase(find(child[xp].begin(), child[xp].end(), x));
			par[x] = -1;
		}

		dfs(root);
		cout << answer;
		return 0;
	}
};