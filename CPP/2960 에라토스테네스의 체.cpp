// https://www.acmicpc.net/problem/2960

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2960
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		bool a[1001]{};
		int n, k;
		cin >> n >> k;
		for (int i = 2; i <= n; ++i)
		{
			if (!a[i])
			{
				for (int j = i; j <= n; j += i)
				{
					if (!a[j])
					{
						a[j] = true;
						--k;
						if (k == 0)
						{
							cout << j;
							i = n;
							break;
						}
					}
				}
			}
		}

		return 0;
	}
};