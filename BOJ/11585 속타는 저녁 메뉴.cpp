// https://www.acmicpc.net/problem/11585

#include <bits/stdc++.h>
using namespace std;

struct p11585
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n;
		cin >> n;
		vector<char> t(n, 0);
		vector<int> f(n, 0);

		int mv = 0;
		int j = 0;
		cin >> t[0];
		for (int i = 1; i < n; ++i)
		{
			cin >> t[i];

			while (j > 0 && t[i] != t[j])
			{
				j = f[j - 1];
			}

			if (t[i] == t[j])
			{
				f[i] = ++j;
				mv = max(mv, f[i]);
			}
		}

		int psize = n - mv;

		if (n % psize != 0)
		{
			cout << "1/" << n;
		}
		else
		{
			int x = n / psize;
			int y = n;

			// gcd
			int a = y, b = x;
			while (b != 0)
			{
				int a2 = a;
				a = b;
				b = a2 % b;
			}

			cout << x / a << "/" << y / a;
		}

		return 0;
	}
};