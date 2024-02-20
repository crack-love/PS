// https://www.acmicpc.net/problem/10162

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10162
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		if (t % 10 > 0)
		{
			cout << -1;
		}
		else
		{
			int a = t / 300;
			t %= 300;
			int b = t / 60;
			t %= 60;
			int c = t / 10;
			t %= 10;

			cout << a << " " << b << " " << c;
		}
		return 0;
	}
};