// https://www.acmicpc.net/problem/11365

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p11365
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		while (true)
		{
			getline(cin, s);
			if (s.compare("END") == 0)
			{
				break;
			}
			else
			{
				for (int i = 0; i < s.size(); ++i)
				{
					cout << s[s.size() - 1 - i];
				}
				cout << "\n";
			}
		}

		return 0;
	}
};