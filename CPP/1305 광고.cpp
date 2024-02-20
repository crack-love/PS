// https://www.acmicpc.net/problem/1305

#include <iostream>
#include <string>
using namespace std;

struct p1305
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int l;
		string s;
		cin >> l >> s;

		int pi[1'000'000] = {};
		int j = 0;
		for (int i = 1; i < l; ++i)
		{
			while (j > 0 && s[i] != s[j])
			{
				j = pi[j - 1];
			}

			if (s[i] == s[j])
			{
				pi[i] = ++j;
			}
		}

		cout << l - pi[l - 1];

		return 0;
	}
};