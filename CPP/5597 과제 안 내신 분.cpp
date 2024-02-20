// https://www.acmicpc.net/problem/5597

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5597
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[30]{};
		for (int i = 0; i < 28; ++i)
		{
			int x;
			cin >> x;
			a[x - 1] = 1;
		}

		for (int i = 0; i < 30; ++i)
		{
			if (a[i] == 0)
			{
				cout << i + 1 << "\n";
			}
		}

		return 0;
	}
};