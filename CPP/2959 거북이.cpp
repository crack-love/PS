// https://www.acmicpc.net/problem/2959

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2959
{
	int main()
	{
		fastio;

		int a[4];
		for1(i, 4)
			cin >> a[i];

		sort(a, a + 4);
		cout << a[2] * a[0];

		return 0;
	}
};