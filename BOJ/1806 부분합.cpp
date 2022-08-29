// https://www.acmicpc.net/problem/1806

#include <bits/stdc++.h>
using namespace std;

struct p1806
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, s, a[(int)1e5], b = 0, e = 1;// [b e)
		cin >> n >> s;
		int sum = 0;
		int answer = (int)1e9;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += a[i];
			e = i + 1;
			while (sum >= s && b < e)
			{
				answer = min(answer, e - b);
				sum -= a[b];
				b += 1;
			}
		}
		cout << (answer == (int)1e9 ? 0 : answer);

		return 0;
	}
};