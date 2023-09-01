// https://www.acmicpc.net/problem/12871

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p12871
{
	int gcd(int x, int y)
	{
		if (x < y) swap(x, y);
		if (y == 0) return x;
		return gcd(y, x % y);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		// abab
		// ababab

		// aba
		// ab

		string s, t;
		cin >> s >> t;

		int g = gcd(s.size(), t.size());
		int m = s.size() * t.size() / g;

		string s1, t1;
		while (s1.size() < m)
			s1 += s;
		while (t1.size() < m)
			t1 += t;

		cout << (s1 == t1 ? 1 : 0);
		return 0;
	}
};