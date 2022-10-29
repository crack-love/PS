// https://www.acmicpc.net/problem/5565

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5565
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int s;
		cin >> s;
		for (int i = 0; i < 9; ++i)
		{
			int x;
			cin >> x;
			s -= x;
		}
		cout << s;

		return 0;
	}
};