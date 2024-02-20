// https://www.acmicpc.net/problem/2587

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2587
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int s = 0;
		int a[5];
		for (int i = 0; i < 5; ++i)
		{
			cin >> a[i];
			s += a[i];
		}

		sort(a, a + 5);
		cout << s / 5 << "\n";
		cout << a[2] << "\n";

		return 0;
	}
};