// https://www.acmicpc.net/problem/16430

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p16430
{
	int gcd(int a, int b)
	{
		if (a < b) swap(a, b);
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b;
		cin >> a >> b;
		a = b - a;
		int g = gcd(a, b);
		cout << a / g << " " << b / g;
		return 0;
	}
};