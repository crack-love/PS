// https://www.acmicpc.net/problem/17219

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p17219
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;

		unordered_map<string, string> s;

		for1(i, n)
		{
			string adr, psw;
			cin >> adr >> psw;
			s.insert({ adr,psw });
		}
		for1(i, m)
		{
			string adr;
			cin >> adr;
			cout << s[adr] << "\n";
		}

		return 0;
	}
};