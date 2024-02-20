// https://www.acmicpc.net/problem/11660

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p11660
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		int s[1025][1025]{};
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int rsum = 0;
			for (int j = 1; j <= n; ++j)
			{
				int x;
				cin >> x;
				rsum += x;
				s[i][j] = s[i - 1][j] + rsum;
			}
		}

		while (m--)
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			int sum = s[x2][y2];
			sum -= s[x2][y1 - 1];
			sum -= s[x1 - 1][y2];
			sum += s[x1 - 1][y1 - 1];
			cout << sum << '\n';
		}

		return 0;
	}
};