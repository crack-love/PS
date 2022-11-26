// https://www.acmicpc.net/problem/10798

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10798
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		char a[16][16]{};
		for (int i = 0; i < 5; ++i)
		{
			cin >> a[i];
		}

		for2(i, j, 15, 15)
		{
			if (a[j][i] != 0)
			{
				cout << a[j][i];
			}
		}

		return 0;
	}
};