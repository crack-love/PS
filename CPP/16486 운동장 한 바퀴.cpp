// https://www.acmicpc.net/problem/16486

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p16486
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int d1, d2;
		cin >> d1 >> d2;

		double ans = d1 * 2;
		double pi = 3.141592;
		ans += 2 * pi * d2;

		cout.precision(6);
		cout.setf(ios::fixed);
		cout << ans;

		return 0;
	}
};