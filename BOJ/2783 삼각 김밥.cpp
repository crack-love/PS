// https://www.acmicpc.net/problem/2783

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2783
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		double x, y;
		cin >> x >> y;
		double p = x / y;

		int n;
		cin >> n;
		for1(i, n)
		{
			double a, b;
			cin >> a >> b;
			double p2 = a / b;
			p = min(p, p2);
		}

		cout.precision(2);
		cout.setf(cout.fixed);
		cout << p * 1000;
		return 0;
	}
};