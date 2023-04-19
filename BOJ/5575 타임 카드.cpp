// https://www.acmicpc.net/problem/5575

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p5575
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		for1(i, 3)
		{
			int hb, mb, sb, he, me, se;
			cin >> hb >> mb >> sb;
			cin >> he >> me >> se;

			int b = (((hb * 60) + mb) * 60) + sb;
			int e = (((he * 60) + me) * 60) + se;
			int d = e - b;

			int as = d % 60;
			d /= 60;
			int am = d % 60;
			d /= 60;
			int ah = d;
			cout << ah << " " << am << " " << as << "\n";
		}

		return 0;
	}
};