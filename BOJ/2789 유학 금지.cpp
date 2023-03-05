// https://www.acmicpc.net/problem/2789

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2789
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string e = "CAMBRIDGE";
		string s;
		cin >> s;
		for (char c : s)
		{
			bool erased = false;
			for1(i, e.size())
			{
				if (c == e[i])
				{
					erased = true;
					break;
				}
			}
			if (!erased)
			{
				cout << c;
			}
		}
		return 0;
	}
};