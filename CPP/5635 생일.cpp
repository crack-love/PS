// https://www.acmicpc.net/problem/5635

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p5635
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		tuple<string, int, int, int> arr[100];

		for1(i, n)
		{
			string name;
			int d, m, y;
			cin >> name >> d >> m >> y;
			arr[i] = { name,d,m,y };
		}

		sort(arr, arr + n, [](const tuple<string, int, int, int>& x,
			const tuple<string, int, int, int>& y)
			{
				const auto& [xn, xd, xm, xy] = x;
				const auto& [yn, yd, ym, yy] = y;

				if (xy != yy)
					return xy < yy;
				else if (xm != ym)
					return xm < ym;
				else
					return xd < yd;
			});

		cout << get<0>(arr[n - 1]) << "\n";
		cout << get<0>(arr[0]);

		return 0;
	}
};