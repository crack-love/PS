// https://www.acmicpc.net/problem/1764

#include <bits/stdc++.h>
using namespace std;

struct p1764
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, m;
		string a[500000];
		string b[500000];
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + n);

		vector<string> ans;
		int i = 0, j = 0;
		while (i < n && j < m)
		{
			int cmp = a[i].compare(b[j]);
			if (cmp == 0)
			{
				ans.push_back(a[i]);
				++i;
				++j;
			}
			else if (cmp < 0)
			{
				++i;
			}
			else if (cmp > 0)
			{
				++j;
			}
		}

		cout << ans.size() << "\n";
		for (string& s : ans)
		{
			cout << s << "\n";
		}

		return 0;
	}
};