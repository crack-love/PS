// https://www.acmicpc.net/problem/2752

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2752
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[3];
		for (int i = 0; i < 3; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + 3);
		for (int i = 0; i < 3; ++i)
		{
			cout << a[i] << " ";
		}

		return 0;
	}
};