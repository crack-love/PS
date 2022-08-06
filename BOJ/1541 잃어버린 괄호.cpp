// https://www.acmicpc.net/problem/1541

#include <bits/stdc++.h>
using namespace std;

struct p1541
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		string s;
		getline(cin, s);
		int ans = 0;
		int v = 0;
		bool isMinus = false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '-' || s[i] == '+')
			{
				ans += isMinus ? -v : v;
				v = 0;
				isMinus |= s[i] == '-';
			}
			else
			{
				v *= 10;
				v += s[i] - '0';
			}
		}
		ans += isMinus ? -v : v;
		cout << ans;

		return 0;
	}
};