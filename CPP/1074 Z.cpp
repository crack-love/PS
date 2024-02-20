// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p1074
{
	bool finished = false;

	int visit(int bx, int by, int ex, int ey, int dx, int dy)
	{
		if (finished)
		{
			return 0;
		}
		else if (bx == ex && by == ey)
		{
			if (bx == dx && by == dy)
			{
				finished = true;
				return 0;
			}
			else
			{
				return 1;
			}
		}

		if (bx <= dx && dx <= ex && by <= dy && dy <= ey)
		{
			int mx = (ex - bx) / 2 + bx;
			int my = (ey - by) / 2 + by;
			int sum = 0;

			// tl, tr
			sum += visit(bx, by, mx, my, dx, dy);
			sum += visit(bx, my + 1, mx, ey, dx, dy);

			// bl, br
			sum += visit(mx + 1, by, ex, my, dx, dy);
			sum += visit(mx + 1, my + 1, ex, ey, dx, dy);
			return sum;
		}
		else
		{
			return (ex - bx + 1) * (ey - by + 1);
		}
	}

	int main()
	{
		int n, r, c;
		cin >> n >> r >> c;
		int end = (int)pow(2, n) - 1;
		cout << visit(0, 0, end, end, r, c);
		return 0;
	}
};