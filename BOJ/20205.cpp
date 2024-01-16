// https://www.acmicpc.net/problem/20205

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p20205
{
	int main()
	{
		fastio;
		int n, k;
		cin >> n >> k;
		int a[10][10];
		for2(i, j, n, n)
		{
			cin >> a[i][j];
		}

		for2(i, j, n * k, n * k)
		{
			cout << a[i / k][j / k] << " ";

			if (j == n * k - 1)
				cout << "\n";
		}

		return 0;
	}
};