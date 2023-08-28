// https://www.acmicpc.net/problem/15781

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p15781
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		int v0 = 0, v1 = 0;
		for1(i, n)
		{
			int x;
			cin >> x;
			v0 = max(v0, x);
		}
		for1(i, m)
		{
			int x;
			cin >> x;
			v1 = max(v1, x);
		}

		cout << v0 + v1;
		return 0;
	}
};