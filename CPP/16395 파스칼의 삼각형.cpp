// https://www.acmicpc.net/problem/16395

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p16395
{
	int main()
	{
		fastio;

		int n, k;
		cin >> n >> k;
		int a[30][30];

		for (int i = 0; i < n; ++i)
		{
			a[i][0] = a[i][i] = 1;
			for (int j = 1; j < i; ++j)
			{
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
		}

		cout << a[n - 1][k - 1];
		return 0;
	}
};