// https://www.acmicpc.net/problem/17298

#include <bits/stdc++.h>
using namespace std;

struct p17298
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int a[(int)1e6];
		int ans[(int)1e6];
		stack<int> s;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];

			while (!s.empty() && a[i] > a[s.top()])
			{
				ans[s.top()] = a[i];
				s.pop();
			}
			s.push(i);
		}

		while (!s.empty())
		{
			ans[s.top()] = -1;
			s.pop();
		}

		for (int i = 0; i < n; ++i)
		{
			cout << ans[i] << " ";
		}

		return 0;
	}
};