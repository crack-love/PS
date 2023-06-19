// https://www.acmicpc.net/problem/4344

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p4344
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int c;
		cin >> c;
		while (c--)
		{
			int sum = 0;
			int n;
			int a[1000];
			cin >> n;
			for1(i, n)
			{
				cin >> a[i];
				sum += a[i];
			}

			double avg = (double)sum / n;

			int above = 0;
			for1(i, n)
			{
				if (a[i] > avg)
				{
					above += 1;
				}
			}

			double p = (double)above * 100 / n;

			p *= 1000;
			p = round(p);
			p /= 1000;

			cout.setf(ios::fixed);
			cout.precision(3);
			cout << p << "%\n";
		}

		return 0;
	}
};