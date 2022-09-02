// https://www.acmicpc.net/problem/2493

#include <bits/stdc++.h>
using namespace std;

struct p2493
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n;
		cin >> n;
		stack<int> s;
		int arr[(int)5e5 + 1];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		int ans[(int)5e5 + 1] = {};
		for (int i = n - 1; i >= 0; --i)
		{
			while (!s.empty() && arr[i] >= arr[s.top()])
			{
				ans[s.top()] = i + 1;
				s.pop();
			}

			// i is smaller than top
			s.push(i);
		}

		for (int i = 0; i < n; ++i)
		{
			cout << ans[i] << " ";
		}

		return 0;
	}
};