// https://www.acmicpc.net/problem/10768

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10768
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int m, d;
		cin >> m >> d;
		if (m < 2 || (m == 2 && d < 18))
		{
			cout << "Before";
		}
		else if (m == 2 && d == 18)
		{
			cout << "Special";
		}
		else
		{
			cout << "After";
		}

		return 0;
	}
};