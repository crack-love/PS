// https://www.acmicpc.net/problem/1251

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1251
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;

		string ans = "";
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = i + 1; j < s.size() - 1; ++j)
			{
				string t = s;
				reverse(t.begin(), t.begin() + i + 1);
				reverse(t.begin() + i + 1, t.begin() + j + 1);
				reverse(t.begin() + j + 1, t.end());
				if (t < ans || ans.size() == 0) ans = t;
			}
		}
		cout << ans;
		return 0;
	}
};