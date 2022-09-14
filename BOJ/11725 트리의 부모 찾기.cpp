// https://www.acmicpc.net/problem/11725

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p11725
{
	vector<int> edge[100001];
	int par[100001];

	void link(int x)
	{
		for (int e : edge[x])
		{
			if (e == par[x]) continue;
			par[e] = x;
			link(e);
		}
	}

	int main()
	{
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		link(1);

		for (int i = 2; i <= n; ++i)
		{
			cout << par[i] << "\n";
		}

		return 0;
	}
};