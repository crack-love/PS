// https://www.acmicpc.net/problem/10810

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p10810
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		int a[100]{};

		for1(i, m)
		{
			int b, e, c;
			cin >> b >> e >> c;
			b -= 1;
			e -= 1;

			for (int j = b; j <= e; ++j)
			{
				a[j] = c;
			}
		}

		for1(i, n)
		{
			cout << a[i] << " ";
		}

		return 0;
	}
};