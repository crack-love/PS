// https://www.acmicpc.net/problem/2108

#include <bits/stdc++.h>
using namespace std;

struct p2108
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int a[(int)5e5];
		int cnt[8001] = {};
		int n;
		cin >> n;

		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			a[i] = x;
			cnt[x + 4000] += 1;
			sum += x;
		}

		sort(a, a + n);

		int mostCnt = 0;
		int mostAns = 0;
		bool isFirst = false;
		for (int i = 0; i < n; ++i)
		{
			int x = a[i];
			int xcnt = cnt[a[i] + 4000];
			if (xcnt == mostCnt && x != mostAns && isFirst)
			{
				isFirst = false;
				mostAns = x;
			}
			else if (xcnt > mostCnt)
			{
				isFirst = true;
				mostCnt = xcnt;
				mostAns = x;
			}
		}

		cout << (int)round(sum / (double)n) << "\n";
		cout << a[n / 2] << "\n";
		cout << mostAns << "\n";
		cout << abs(a[0] - a[n - 1]) << "\n";
		return 0;
	}
};