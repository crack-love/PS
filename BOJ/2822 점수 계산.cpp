// https://www.acmicpc.net/problem/2822

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2822
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		pair<int, int> a[8]{};
		for1(i, 8)
		{
			int x;
			cin >> x;
			a[i] = { x,i + 1 };
		}
		sort(a, a + 8, greater<pair<int, int>>());

		int b[5];
		int sum = 0;
		for1(i, 5)
		{
			sum += a[i].first;
			b[i] = a[i].second;
		}
		sort(b, b + 5);

		cout << sum << "\n";

		for1(i, 5)
		{
			cout << b[i] << " ";
		}

		return 0;
	}
};