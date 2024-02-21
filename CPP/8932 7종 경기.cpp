// https://www.acmicpc.net/problem/8932

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p8932
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		struct p
		{
			double a, b, c;
			int species;
			double p;
			long long v()
			{
				if (species == 0)
				{
					return (long long)a * (long long)pow(b - p, c);
				}
				else
				{
					return (long long)a * (long long)pow(p - b, c);
				}
			}
		}
		p[7]
		{
			{9.23076, 26.7, 1.835, 0},
			{1.84523, 75, 1.348, 1},
			{56.0211, 1.5, 1.05, 1},
			{4.99087, 42.5, 1.81, 0},
			{0.188807, 210, 1.41, 1},
			{15.9803, 3.8, 1.04, 1},
			{0.11193, 254, 1.88, 0}
		};

		int t;
		cin >> t;
		while (t--)
		{
			long long ans = 0;
			for1(i, 7)
			{
				cin >> p[i].p;
				ans += p[i].v();
			}

			cout << ans << "\n";
		}

		return 0;
	};
};