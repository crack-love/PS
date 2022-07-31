// https://www.acmicpc.net/problem/10266

#include <bits/stdc++.h>
using namespace std;

struct p10266
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		const int MAX = 360'000;
		int n;
		int a[MAX] = {};
		int b[MAX] = {};
		cin >> n;
		for (int i = 0; i < n * 2; ++i)
		{
			int x;
			cin >> x;
			if (i < n)
			{
				a[x] = 1;
			}
			else
			{
				b[x] = 1;
			}
		}

		int f[MAX] = {};
		int j = 0;
		for (int i = 1; i < MAX; ++i)
		{
			while (j > 0 && b[i] != b[j])
			{
				j = f[j - 1];
			}

			if (b[i] == b[j])
			{
				f[i] = ++j;
			}
		}

		int bi = 0;
		for (int i = 0; i < MAX * 2; ++i)
		{
			int ai = i % MAX;
			while (bi > 0 && a[ai] != b[bi])
			{
				bi = f[bi - 1];
			}

			if (a[ai] == b[bi])
			{
				bi += 1;
				if (bi >= MAX)
				{
					break;
				}
			}
		}

		if (bi >= MAX)
		{
			cout << "possible";
		}
		else
		{
			cout << "impossible";
		}
		return 0;
	}
};