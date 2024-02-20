// https://www.acmicpc.net/problem/2511

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2511
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[10];
		int as = 0, bs = 0;
		int lastw = -1;

		for1(i, 10)
		{
			cin >> a[i];
		}
		for1(i, 10)
		{
			int b;
			cin >> b;

			if (a[i] > b)
			{
				as += 3;
				lastw = 0;
			}
			else if (b > a[i])
			{
				bs += 3;
				lastw = 1;
			}
			else
			{
				as += 1;
				bs += 1;
			}
		}

		cout << as << " " << bs << "\n";
		if (as > bs)
		{
			cout << "A";
		}
		else if (bs > as)
		{
			cout << "B";
		}
		else if (lastw == -1)
		{
			cout << "D";
		}
		else
		{
			cout << (lastw == 0 ? "A" : "B");
		}

		return 0;
	}
};