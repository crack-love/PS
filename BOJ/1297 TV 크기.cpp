// https://www.acmicpc.net/problem/1297

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1297
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int d, h, w;
		cin >> d >> h >> w;

		// wwcc+hhcc=dd
		// ww+hh=dd/cc
		// cc=dd/wwhh
		// W = w*c

		int dd = d * d;
		int wwhh = w * w + h * h;
		double cc = (double)dd / wwhh;
		double c = sqrt(cc);

		cout << (int)(h * c) << " " << (int)(w * c);

		return 0;
	}
};