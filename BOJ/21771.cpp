// https://www.acmicpc.net/problem/21771

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p21771
{
	int main()
	{
		fastio;

		int r, c, rg, cg, rp, cp;
		cin >> r >> c >> rg >> cg >> rp >> cp;

		int rpmin = 100, cpmin = 100;
		int rpmax = 0, cpmax = 0;

		char g[100][100];
		for2(i, j, r, c)
		{
			cin >> g[i][j];
			if (g[i][j] == 'P')
			{
				rpmin = min(rpmin, i);
				cpmin = min(cpmin, j);
				rpmax = max(rpmax, i);
				cpmax = max(cpmax, j);
			}
		}

		// single side 
		if (rpmax - rpmin + 1 < rp || cpmax - cpmin + 1 < cp)
		{
			cout << 1;
			return 0;
		}

		for2(i, j, rp, cp)
		{
			int x = i + rpmin;
			int y = j + cpmin;
			if (g[x][y] == 'G')
			{
				cout << 1;
				return 0;
			}
		}

		cout << 0;
		return 0;
	}
};