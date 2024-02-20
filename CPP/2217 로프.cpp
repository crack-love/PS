// https://www.acmicpc.net/problem/2217

#include <bits/stdc++.h>
using namespace std;

struct p2217
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n;
		int a[(int)1e5];
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		sort(a, a + n, greater<int>());

		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans = max(ans, a[i] * (i + 1));
		}
		cout << ans;
		return 0;
	}
};