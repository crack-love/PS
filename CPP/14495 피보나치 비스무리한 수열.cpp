// https://www.acmicpc.net/problem/14495

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p14495
{
	ll d[117]{};
	ll dd(int x)
	{
		if (d[x] != 0)
			return d[x];
		if (x <= 3)
			return 1;
		return d[x] = dd(x - 3) + dd(x - 1);
	}

	int main()
	{
		fastio;

		int n;
		cin >> n;

		cout << dd(n);
		return 0;
	}
};