// https://www.acmicpc.net/problem/23808

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p23808
{
	int main()
	{
		fastio;

		int n;
		cin >> n;

		int g[500][500]{};

		for (int i = 0; i < 5 * n; ++i)
		{
			for (int j = 0; j < n; ++j)
				g[i][j] = 1;
			for (int j = 4 * n; j < 5 * n; ++j)
				g[i][j] = 1;
		}

		for (int j = 0; j < 5 * n; ++j)
		{
			for (int i = 2 * n; i < 3 * n; ++i)
				g[i][j] = 1;
			for (int i = 4 * n; i < 5 * n; ++i)
				g[i][j] = 1;
		}

		for2(i, j, n * 5, n * 5)
		{
			cout << (g[i][j] ? "@" : " ");
			if (j == n * 5 - 1)
				cout << "\n";
		}

		return 0;
	}
};