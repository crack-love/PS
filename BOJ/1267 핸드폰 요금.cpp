// https://www.acmicpc.net/problem/1267

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1267
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;

		int s0 = 0;
		int s1 = 0;
		for1(i, n)
		{
			int x;
			cin >> x;

			s0 += ((x / 30) + 1) * 10;
			s1 += ((x / 60) + 1) * 15;
		}

		if (s0 == s1)
		{
			cout << "Y M " << s0;
		}
		else if (s0 < s1)
		{
			cout << "Y " << s0;
		}
		else
		{
			cout << "M " << s1;
		}

		return 0;
	}
};