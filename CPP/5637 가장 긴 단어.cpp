// https://www.acmicpc.net/problem/5637

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p5637
{
	int main()
	{
		fastio;

		string ans;
		regex re("[a-zA-Z\-]+");

		while (true)
		{
			string s;
			cin >> s;
			if (s == "E-N-D")
				break;

			auto beg = sregex_iterator(all(s), re);
			auto end = sregex_iterator();
			while (beg != end)
			{
				string m = beg->str();
				if (m.size() > ans.size())
				{
					ans = m;
				}
				++beg;
			}
		}

		for (int i = 0; i < ans.size(); ++i)
			ans[i] = tolower(ans[i]);
		cout << ans;
		return 0;
	}
};