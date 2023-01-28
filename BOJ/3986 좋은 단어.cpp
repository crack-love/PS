// https://www.acmicpc.net/problem/3986

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p3986
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int ans = 0;
		while (n--)
		{
			string s;
			cin >> s;

			stack<char>st;
			for1(i, s.size())
			{
				if (st.empty())
				{
					st.push(s[i]);
				}
				else
				{
					if (st.top() == s[i])
					{
						st.pop();
					}
					else
					{
						st.push(s[i]);
					}
				}
			}

			if (st.empty())
			{
				ans += 1;
			}
		}

		cout << ans;
		return 0;
	}
};