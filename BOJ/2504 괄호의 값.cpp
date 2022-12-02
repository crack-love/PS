// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2504
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string str;
		cin >> str;

		stack<char> st;
		int answer = 0;
		int multi = 1;
		bool opened = false;
		for (int i = 0; i < str.size(); ++i)
		{
			char c = str[i];

			if (c == '(')
			{
				opened = true;
				multi *= 2;
				st.push(c);
			}
			else if (c == '[')
			{
				opened = true;
				multi *= 3;
				st.push(c);
			}
			else if (c == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					if (opened)
					{
						answer += multi;
						opened = false;
					}
					multi /= 2;
					st.pop();
				}
				else
				{
					answer = 0;
					break;
				}
			}
			else if (c == ']')
			{
				if (!st.empty() && st.top() == '[')
				{
					if (opened)
					{
						answer += multi;
						opened = false;
					}
					multi /= 3;
					st.pop();
				}
				else
				{
					answer = 0;
					break;
				}
			}
		}

		if (st.size() > 0)
		{
			answer = 0;
		}
		cout << answer;
		return 0;
	}
};