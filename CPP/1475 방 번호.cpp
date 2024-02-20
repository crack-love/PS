// https://www.acmicpc.net/problem/1475

#include <bits/stdc++.h>
using namespace std;
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)

struct p1475
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n;
		cin >> n;
		int a[10]{};
		while (n > 0)
		{
			a[n % 10] += 1;
			n /= 10;
		}
		a[6] = (int)ceil((a[6] + a[9]) / (double)2);
		a[9] = 0;
		int max = 0;
		for (int i = 0; i < 10; ++i)
		{
			if (a[i] > max) max = a[i];
		}
		cout << max;
		return 0;
	}
};