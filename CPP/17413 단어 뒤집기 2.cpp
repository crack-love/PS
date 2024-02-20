// https://www.acmicpc.net/problem/17413

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p17413
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		stack<char> st;
		getline(cin, s);

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '<')
			{
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}

				cout << s[i];
				do
				{
					++i;
					cout << s[i];
				} while (s[i] != '>');
			}
			else if (s[i] == ' ')
			{
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}
				cout << s[i];
			}
			else
			{
				st.push(s[i]);
			}
		}

		while (!st.empty())
		{
			cout << st.top();
			st.pop();
		}

		return 0;
	}
};