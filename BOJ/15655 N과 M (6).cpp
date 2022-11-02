// https://www.acmicpc.net/problem/15655

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p15655
{
	int a[8];
	int n, m;
	vector<int> picked;
	void print(int i)
	{
		if (picked.size() >= m)
		{
			for (int p : picked)
			{
				cout << p << " ";
			}
			cout << "\n";
			return;
		}

		for (int j = i; j < n; ++j)
		{
			picked.push_back(a[j]);
			print(j + 1);
			picked.pop_back();
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
		print(0);

		return 0;
	}
};