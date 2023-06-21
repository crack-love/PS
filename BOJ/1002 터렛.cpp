// https://www.acmicpc.net/problem/1002

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1002
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		//freopen("1002.txt", "r", stdin);

		int t;
		cin >> t;
		while (t--)
		{
			int x, y, r, x1, y1, r1;
			cin >> x >> y >> r >> x1 >> y1 >> r1;

			// collapsed
			if (x == x1 && y == y1)
			{
				if (r == r1)
				{
					cout << (r == 0 ? 1 : -1);
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				double d = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));

				if (d > r + r1)
				{
					cout << 0;
				}
				else if (d == r + r1)
				{
					cout << 1;
				}
				else
				{
					if (d + r == r1 || d + r1 == r)
					{
						cout << 1;
					}
					else if (d + r < r1 || d + r1 < r)
					{
						cout << 0;
					}
					else
					{
						cout << 2;
					}
				}
			}
			cout << "\n";
		}

		return 0;
	}
};