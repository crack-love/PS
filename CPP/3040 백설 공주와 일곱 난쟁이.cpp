// https://www.acmicpc.net/problem/3040

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p3040
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int f[9] = { 1,1 };
		int a[9];
		for1(i, 9)
		{
			cin >> a[i];
		}

		do
		{
			int s = 0;
			for1(i, 9)
			{
				if (!f[i])
				{
					s += a[i];
				}
			}
			if (s == 100)
			{
				for1(i, 9)
				{
					if (!f[i])
					{
						cout << a[i] << "\n";
					}
				}
				return 0;
			}
		} while (prev_permutation(f, f + 9));

		return 0;
	}
};