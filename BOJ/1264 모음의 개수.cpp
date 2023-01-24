// https://www.acmicpc.net/problem/1264

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1264
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string p = "aeiou";

		while (true)
		{
			string s;
			getline(cin, s);
			if (s[0] == '#')
			{
				break;
			}

			int cnt = 0;
			for (char c : s)
			{
				c = tolower(c);
				for (char pp : p)
				{
					if (c == pp)
					{
						cnt += 1;
					}
				}
			}
			cout << cnt << "\n";
		}

		return 0;
	}
};