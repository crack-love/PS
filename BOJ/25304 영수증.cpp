// https://www.acmicpc.net/problem/25304

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p25304
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int x, n;
		int sum = 0;
		cin >> x >> n;
		while (n--)
		{
			int a, b;
			cin >> a >> b;
			sum += a * b;
		}

		cout << (sum == x ? "Yes" : "No");

		return 0;
	}
};