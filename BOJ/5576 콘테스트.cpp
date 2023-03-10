// https://www.acmicpc.net/problem/5576

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5576
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[10];
		int b[10];
		for1(i, 10)
		{
			cin >> a[i];
		}
		for1(i, 10)
		{
			cin >> b[i];
		}
		sort(a, a + 10, greater<int>());
		sort(b, b + 10, greater<int>());
		int s0 = 0, s1 = 0;
		for1(i, 3)
		{
			s0 += a[i];
			s1 += b[i];
		}
		cout << s0 << " " << s1;

		return 0;
	}
};
