// https://www.acmicpc.net/problem/5361

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p5361
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		while (t--)
		{
			int a, b, c, d, e;
			cin >> a >> b >> c >> d >> e;
			double s = 0;
			s += a * 350.34;
			s += b * 230.90;
			s += c * 190.55;
			s += d * 125.30;
			s += e * 180.90;
			cout.setf(cout.fixed);
			cout.precision(2);
			cout << "$" << s << "\n";
		}

		return 0;
	}
};