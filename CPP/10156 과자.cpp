// https://www.acmicpc.net/problem/10156

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10156
{

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int k, n, m;
		cin >> k >> n >> m;
		if (k * n <= m)
		{
			cout << "0";
		}
		else
		{
			cout << k * n - m;
		}

		return 0;
	}
};