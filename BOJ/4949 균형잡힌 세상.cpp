// https://www.acmicpc.net/problem/4949

#include <bits/stdc++.h>
using namespace std;

struct p4949
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		stack<char> st;
		string str;

		while (true)
		{
			getline(cin, str);
			if (str[0] == '.')
			{
				break;
			}

			while (!st.empty())
			{
				st.pop();
			}

			bool isFail = false;

			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i] == '(' || str[i] == '[')
				{
					st.push(str[i]);
				}
				else if (str[i] == ')')
				{
					if (st.size() == 0 || st.top() != '(')
					{
						isFail = true;
						break;
					}
					else
					{
						st.pop();
					}
				}
				else if (str[i] == ']')
				{
					if (st.size() == 0 || st.top() != '[')
					{
						isFail = true;
						break;
					}
					else
					{
						st.pop();
					}
				}
			}

			if (st.size() > 0)
			{
				isFail = true;
			}

			cout << (isFail ? "no" : "yes") << "\n";
		}

		return 0;
	}
};