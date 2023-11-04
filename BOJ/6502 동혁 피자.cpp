// https://www.acmicpc.net/problem/6502

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

struct p6502
{
	int main()
	{
		//fastio;

		int tc = 0;
		while (++tc)
		{
			double r, w, l;
			cin >> r;
			if (r == 0)
				break;
			cin >> w >> l;

			// sq(w2+l2) <= 2r
			// w2+l2 <= 4r2

			cout << "Pizza " << tc << " ";
			if (w * w + l * l <= 4 * r * r)
			{
				cout << "fits on the table.\n";
			}
			else
			{
				cout << "does not fit on the table.\n";
			}
		}

		return 0;
	}
};