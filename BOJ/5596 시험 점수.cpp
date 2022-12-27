// https://www.acmicpc.net/problem/5596

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5596
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int s = 0, t = 0;
		for (int i = 0; i < 4; ++i)
		{
			int x;
			cin >> x;
			s += x;
		}
		for (int i = 0; i < 4; ++i)
		{
			int x;
			cin >> x;
			t += x;
		}

		if (s >= t)
		{
			cout << s;
		}
		else
		{
			cout << t;
		}

		return 0;
	}
};