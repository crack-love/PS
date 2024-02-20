// https://www.acmicpc.net/problem/2011

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2011
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;
		int c[5000][2]{ 1,1, }; // not/use

		if (s.size() > 5000)
		{
			cout << 0;
			return 0;
		}
		if (s[0] < '1' || '9' < s[0])
		{
			cout << 0;
			return 0;
		}

		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] < '0' || '9' < s[i])
			{
				cout << 0;
				return 0;
			}

			// merge 0
			if (s[i] == '0')
			{
				if (s[i - 1] == '1' || s[i - 1] == '2')
				{
					c[i][1] += c[i - 1][0];
				}
				// can't merge zero
				else
				{
					cout << 0;
					return 0;
				}
			}
			// merge 1
			else if (s[i - 1] == '1')
			{
				c[i][1] += c[i - 1][0];
			}
			// merge 2
			else if (s[i - 1] == '2' && s[i] <= '6')
			{
				c[i][1] += c[i - 1][0];
			}

			if (s[i] != '0')
			{
				// not use current
				c[i][0] += c[i - 1][1];

				// use current
				c[i][1] += c[i - 1][1];
			}

			c[i][0] %= (int)1e6;
			c[i][1] %= (int)1e6;
		}

		cout << c[s.size() - 1][1];

		return 0;
	}
};