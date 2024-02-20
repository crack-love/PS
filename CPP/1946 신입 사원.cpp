// https://www.acmicpc.net/problem/1946

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1946
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		tuple<int, int> p[(int)1e5];

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				int a, b;
				cin >> a >> b;
				p[i] = { a, b };
			}


			sort(p, p + n);

			int cnt = 0;
			int lb = n + 1;
			for (int i = 0; i < n; ++i)
			{
				auto [a, b] = p[i];

				if (b < lb)
				{
					lb = b;
					cnt += 1;
				}
			}

			cout << cnt << "\n";
		}


		return 0;
	}
};