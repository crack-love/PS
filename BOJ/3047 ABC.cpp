// https://www.acmicpc.net/problem/3047

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p3047
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[3];
		for1(i, 3)
		{
			cin >> a[i];
		}
		sort(a, a + 3);
		for1(i, 3)
		{
			char x;
			cin >> x;
			cout << a[x - 'A'] << " ";
		}

		return 0;
	}
};