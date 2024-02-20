// https://www.acmicpc.net/problem/2744

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2744
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			if (islower(s[i]))
			{
				s[i] = s[i] - 'a' + 'A';
			}
			else if (isupper(s[i]))
			{
				s[i] = s[i] - 'A' + 'a';
			}
		}
		cout << s;
		return 0;
	}
};