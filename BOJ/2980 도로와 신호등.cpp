// https://www.acmicpc.net/problem/2980

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2980
{
	int main()
	{
		fastio;

		int n, l;
		cin >> n >> l;

		int t = 0;
		int p = 0;
		for1(i, n)
		{
			int d, r, g;
			cin >> d >> r >> g;

			// move to d
			t += d - p;
			p = d;

			// wait r
			int tt = t % (r + g);
			if (tt <= r)
			{
				t += r - tt;
			}
		}
		t += l - p;

		cout << t;

		return 0;
	}
};