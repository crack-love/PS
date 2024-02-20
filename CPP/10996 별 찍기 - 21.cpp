// https://www.acmicpc.net/problem/10996

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10996
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					cout << (k % 2 == j ? '*' : ' ');
				}
				cout << '\n';
			}
		}

		return 0;
	}
};