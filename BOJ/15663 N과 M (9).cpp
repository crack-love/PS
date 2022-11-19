// https://www.acmicpc.net/problem/15663

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

int n, m;
int a[8];
vector<int> v;

void solve(int idx, int rvisit)
{
	if (idx >= m)
	{	
		for (int i = 0; i < m; ++i)
		{
			cout << a[v[i]] << " ";
		}
		cout << "\n";
		return;
	}

	unordered_set<int> cvisit;
	for (int j = 0; j < n; ++j)
	{
		if (rvisit & (1 << j)) continue;
		if (cvisit.find(a[j]) != cvisit.end()) continue;

		cvisit.insert(a[j]);

		v.push_back(j);
		solve(idx + 1, rvisit | (1 << j));
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
	solve(0, 0);

	return 0;
}