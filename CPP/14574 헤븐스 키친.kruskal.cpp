// https://www.acmicpc.net/problem/14574

#include <bits/stdc++.h>
using namespace std;

struct p14574_kruskal
{
	static const int SIZE = (int)1e3;
	int par[SIZE];
	vector<int> link[SIZE];

	int getRoot(int i)
	{
		if (par[i] == i)
			return i;
		else
			return par[i] = getRoot(par[i]);
	}

	void dfs(int i, int p)
	{
		for (int l : link[i])
		{
			if (l == p) continue;
			dfs(l, i);
		}

		if (i != p)
		{
			cout << p + 1 << " " << i + 1 << "\n";
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int ps[SIZE];
		int cs[SIZE];
		typedef tuple<int, int, int> tp; // value, i, j
		vector<tp> v;

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> ps[i] >> cs[i];
			par[i] = i;

			for (int j = 0; j < i; ++j)
			{
				int value = (cs[i] + cs[j]) / abs(ps[i] - ps[j]);
				v.push_back({ value, i, j });
			}
		}

		sort(v.begin(), v.end(), greater<tp>());

		long long answer = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			int value, a, b;
			tie(value, a, b) = v[i];
			if (getRoot(a) == getRoot(b)) continue;

			// merge
			if (getRoot(a) > getRoot(b)) swap(a, b);
			par[getRoot(b)] = getRoot(a);

			answer += value;
			link[a].push_back(b);
			link[b].push_back(a);
		}

		cout << answer << "\n";
		int r = getRoot(0);
		dfs(r, r);

		return 0;
	}
};