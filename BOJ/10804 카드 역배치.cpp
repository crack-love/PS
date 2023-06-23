// https://www.acmicpc.net/problem/10804

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p10804
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[21];
		for1(i, 21)
		{
			a[i] = i;
		}

		for1(i, 10)
		{
			int x, y;
			cin >> x >> y;

			int size = (y - x + 1) / 2;
			for1(j, size)
			{
				int t = a[x + j];
				a[x + j] = a[y - j];
				a[y - j] = t;
			}
		}

		for1(i, 20)
		{
			cout << a[i + 1] << " ";
		}

		return 0;
	}
};