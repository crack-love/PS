// https://www.acmicpc.net/problem/10987

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10987
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<char> t{ 'a', 'e', 'i', 'o', 'u' };
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j < t.size(); ++j)
			{
				if (s[i] == t[j])
				{
					cnt += 1;
					break;
				}
			}
		}
		cout << cnt;
		return 0;
	}
};