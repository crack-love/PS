// https://www.acmicpc.net/problem/11866

#include <bits/stdc++.h>
using namespace std;

struct p11866
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int next[1000] = {};
		int prev[1000] = {};
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			next[i] = (i + 1) % n;
			prev[i] = (i - 1 + n) % n;
		}

		vector<int> ans;
		int ptr = (k - 1 + n) % n;
		int cnt = 0;
		while (cnt < n)
		{
			ans.push_back(ptr);
			next[prev[ptr]] = next[ptr];
			prev[next[ptr]] = prev[ptr];
			cnt += 1;

			for (int i = 0; i < k; ++i)
			{
				ptr = next[ptr];
			}
		}

		cout << "<";
		for (int i = 0; i < ans.size(); ++i)
		{
			if (i != 0)
				cout << ", ";

			cout << ans[i] + 1;
		}
		cout << ">";

		return 0;
	}
};