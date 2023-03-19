// https://www.acmicpc.net/problem/9625

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9625
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		// b - ba
		// a - b
		// bi = bi-1 + ai-1
		// ai = bi-1

		int k;
		cin >> k;

		int bc = 0;
		int ac = 1;
		for1(i, k)
		{
			int nbc = bc + ac;
			int nac = bc;
			bc = nbc;
			ac = nac;
		}

		cout << ac << " " << bc;


		return 0;
	}
};