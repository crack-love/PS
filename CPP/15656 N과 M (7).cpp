// https://www.acmicpc.net/problem/15656

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p15656
{
	int n, m;
	int a[7];
	vector<int> v;
	void dfs(int idx)
	{
		if (v.size() >= m)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i] << " ";
			}
			cout << "\n";
			return;
		}

		for (int j = 0; j < n; ++j)
		{
			v.push_back(a[j]);
			dfs(idx + 1);
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