// https://www.acmicpc.net/problem/6064

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p6064
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int m, n, x, y;
			cin >> m >> n >> x >> y;

			int d = m % n;
			int cnt = x;
			int y1 = cnt % n;
			if (y1 == 0) y1 = n;
			bool visited[40001]{};
			while (true)
			{
				if (visited[y1])
				{
					cout << -1 << "\n";
					break;
				}
				else
				{
					visited[y1] = true;
					if (y1 == y)
					{
						cout << cnt << "\n";;
						break;
					}
					else
					{
						y1 = (y1 + d) % n;
						if (y1 == 0) y1 = n;
						cnt += m;
					}
				}
			}
		}

		return 0;
	}
};