// https://www.acmicpc.net/problem/15657

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p15657
{
	int n, m;
	int a[8];
	vector<int> s;

	void print(int idx)
	{
		if (s.size() >= m)
		{
			for (auto v : s)
			{
				cout << v << " ";
			}
			cout << "\n";
		}
		else
		{
			for (int i = idx; i < n; ++i)
			{
				s.push_back(a[i]);
				print(i);
				s.pop_back();
			}
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