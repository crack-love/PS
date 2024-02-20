// https://www.acmicpc.net/problem/5554

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p5554
{

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int s = 0;
		for (int i = 0; i < 4; ++i)
		{
			int x;
			cin >> x;
			s += x;
		}

		cout << s / 60 << "\n";
		cout << s % 60 << "\n";

		return 0;
	}
};