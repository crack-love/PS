// https://www.acmicpc.net/problem/4354

#include <bits/stdc++.h>
using namespace std;

struct p4354
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		string s;
		int pi[(int)1e6];
		while (true)
		{
			cin >> s;
			if (s[0] == '.') break;

			fill(pi, pi + s.size(), 0);

			int j = 0;
			for (int i = 1; i < s.size(); ++i)
			{
				while (j > 0 && s[j] != s[i])
				{
					j = pi[j - 1];
				}
				if (s[j] == s[i])
				{
					pi[i] = ++j;
				}
			}

			// find 1234..
			int beg = -1;
			int cnt = 1;
			for (int i = 0; i < s.size(); ++i)
			{
				if (pi[i] == cnt)
				{
					if (cnt == 1) beg = i;
					++cnt;
				}
				else if (pi[i] == 1)
				{
					cnt = 2;
					beg = i;
				}
				else
				{
					cnt = 1;
					beg = -1;
				}
			}

			if (beg == -1) // beg is pattern's size
			{
				cout << "1\n";
				continue;
			}
			if (s.size() % beg != 0)
			{
				cout << "1\n";
				continue;
			}

			cout << s.size() / beg << "\n";
		}

		return 0;
	}
};