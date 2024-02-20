// https://www.acmicpc.net/problem/10539

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p10539
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a[100];
		int n;
		cin >> n;
		for1(i, n)
		{
			cin >> a[i];
		}

		// (sum + vi) / n = ai
		// ai*n-sum = vi

		int s = 0;
		for1(i, n)
		{
			int v = a[i] * (i + 1) - s;
			cout << v << " ";

			s += v;
		}

		return 0;
	}
};