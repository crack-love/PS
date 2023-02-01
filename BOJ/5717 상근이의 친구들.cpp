// https://www.acmicpc.net/problem/5717

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5717
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		while (true)
		{
			int m, f;
			cin >> m >> f;
			if (m == 0 && f == 0)
			{
				break;
			}
			cout << m + f << "\n";
		}

		return 0;
	}
};