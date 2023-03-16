// https://www.acmicpc.net/problem/1935

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1935
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;

		string s;
		cin >> s;

		int v[26];
		for1(i, n)
		{
			cin >> v[i];
		}

		stack<double> st;
		for1(i, s.size())
		{
			if ('A' <= s[i] && s[i] <= 'Z')
			{
				st.push(v[s[i] - 'A']);
				continue;
			}

			double y = st.top(); st.pop();
			double x = st.top(); st.pop();

			if (s[i] == '*')
			{
				st.push(x * y);
			}
			else if (s[i] == '+')
			{
				st.push(x + y);
			}
			else if (s[i] == '-')
			{
				st.push(x - y);
			}
			else if (s[i] == '/')
			{
				st.push(x / y);
			}
		}

		cout.setf(cout.fixed);
		cout.precision(2);
		cout << st.top();

		return 0;
	}
};