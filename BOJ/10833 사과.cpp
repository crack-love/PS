// https://www.acmicpc.net/problem/10833

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10833
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int s = 0;
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			s += b % a;
		}
		cout << s;
		return 0;
	}
};