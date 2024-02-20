// https://www.acmicpc.net/problem/11948

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p11948
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[4], b[2];
		for1(i, 4)
		{
			cin >> a[i];
		}
		for1(i, 2)
		{
			cin >> b[i];
		}
		sort(a, a + 4, greater<int>());
		sort(b, b + 2, greater<int>());
		int sum = b[0];
		for1(i, 3)
		{
			sum += a[i];
		}
		cout << sum;

		return 0;
	}
};