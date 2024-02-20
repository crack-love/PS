// https://www.acmicpc.net/problem/14425

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p14425
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		unordered_set<string> s;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			string ss;
			cin >> ss;
			s.insert(ss);
		}

		int cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			string ss;
			cin >> ss;
			if (s.find(ss) != s.end())
			{
				cnt += 1;
			}
		}
		cout << cnt;
		return 0;
	}
};