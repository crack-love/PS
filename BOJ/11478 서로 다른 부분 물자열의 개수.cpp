// https://www.acmicpc.net/problem/11478

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p11478
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;
		set<string> se;

		string c;
		int size = s.size();
		for1(i, size)
		{
			c.clear();
			for (int j = i; j < size; ++j)
			{
				c.push_back(s[j]);
				auto it = se.find(c);
				if (it == se.end())
				{
					se.insert(it, c);
				}
			}
		}

		cout << se.size();

		return 0;
	}
};