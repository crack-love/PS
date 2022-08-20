// https://www.acmicpc.net/problem/5585

#include <bits/stdc++.h>
using namespace std;

struct p5585
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int coins[]{ 500, 100, 50, 10, 5, 1 };
		int x;

		cin >> x;
		x = 1000 - x;
		int cnt = 0;
		for (int i = 0; i < 6; ++i)
		{
			cnt += x / coins[i];
			x %= coins[i];
		}

		cout << cnt;
		return 0;
	}
};