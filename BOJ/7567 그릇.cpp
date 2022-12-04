// https://www.acmicpc.net/problem/7567

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p7567
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;
		int ans = 10;
		char last = s[0];
		for (int i = 1; i < s.size(); ++i)
		{
			if (last == '(')
			{
				if (s[i] == ')')
				{
					ans += 10;
				}
				else
				{
					ans += 5;
				}
			}
			else if (last == ')')
			{
				if (s[i] == '(')
				{
					ans += 10;
				}
				else
				{
					ans += 5;
				}
			}
			last = s[i];
		}
		cout << ans;
		return 0;
	}
};