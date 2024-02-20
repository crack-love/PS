// https://www.acmicpc.net/problem/6810

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p6810
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s = "9780921418";
		int ans = 0;
		bool bi = true;
		for1(i, s.size())
		{
			ans += (s[i] - '0') * (bi ? 1 : 3);
			bi = !bi;
		}

		for1(i, 3)
		{
			int x;
			cin >> x;
			ans += x * (bi ? 1 : 3);
			bi = !bi;
		}

		cout << "The 1-3-sum is " << ans;

		return 0;
	}
};