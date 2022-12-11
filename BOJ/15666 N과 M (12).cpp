// https://www.acmicpc.net/problem/15666

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p15666
{
	int n, m;
	int a[8];
	vector<int> v;
	void dfs(int i)
	{
		if (v.size() >= m)
		{
			for (int a : v)
			{
				cout << a << " ";
			}
			cout << "\n";
			return;
		}

		for (i; i < n; ++i)
		{
			if (i > 0 && a[i] == a[i - 1])
			{
				continue;
			}

			v.push_back(a[i]);
			dfs(i);
			v.pop_back();
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		dfs(0);

		return 0;
	}
};