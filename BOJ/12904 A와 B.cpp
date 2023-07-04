// https://www.acmicpc.net/problem/12904

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p12904
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s, t;
		cin >> s >> t;

		while (true)
		{
			if (t.size() <= s.size())
			{
				cout << (t == s ? 1 : 0);
				return 0;
			}

			if (t.back() == 'A')
			{
				t.pop_back();
			}
			else if (t.back() == 'B')
			{
				t.pop_back();
				for (int i = 0; i < t.size() / 2; ++i)
				{
					int x = t.size() - i - 1;
					char tmp = t[x];
					t[x] = t[i];
					t[i] = tmp;
				}
			}
		}

		return 0;
	}
};