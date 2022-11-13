// https://www.acmicpc.net/problem/1918

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1918
{
	string solve(vector<string> v)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == ")")
			{
				for (int j = i - 1; j >= 0; --j)
				{
					if (v[j] == "(")
					{
						vector<string> v1;
						for (int k = j + 1; k < i; ++k)
						{
							v1.push_back(v[k]);
						}

						v[j] = solve(v1);

						int cnt = v1.size() + 1;
						while (cnt--)
						{
							v.erase(v.begin() + j + 1);
						}
						break;
					}
				}
				i = 0;
				continue;
			}
		}

		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == "*" || v[i] == "/")
			{
				v[i - 1] = v[i - 1] + v[i + 1] + v[i];
				v.erase(v.begin() + i);
				v.erase(v.begin() + i);
				i = 0;
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == "+" || v[i] == "-")
			{
				v[i - 1] = v[i - 1] + v[i + 1] + v[i];
				v.erase(v.begin() + i);
				v.erase(v.begin() + i);
				i = 0;
			}
		}

		return v[0];
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;

		vector<string> v;
		for (int i = 0; i < s.size(); ++i)
		{
			v.push_back(string(1, s[i]));
		}
		cout << solve(v);
		return 0;
	}
};