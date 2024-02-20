// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10984
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;

			int csum = 0;
			double gsum = 0;
			for1(i, n)
			{
				int c;
				double g;
				cin >> c >> g;
				csum += c;
				gsum += g * c;
			}

			cout << csum << " ";
			cout.setf(ios::fixed);
			cout.precision(1);
			cout << gsum / csum << "\n";
		}

		return 0;
	}
};