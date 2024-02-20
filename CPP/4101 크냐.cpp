// https://www.acmicpc.net/problem/4101

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p4101
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b;
		while (true)
		{
			cin >> a >> b;
			if (a == 0 && b == 0)
			{
				break;
			}
			cout << (a > b ? "Yes" : "No") << "\n";
		}

		return 0;
	}
};