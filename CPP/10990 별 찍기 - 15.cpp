// https://www.acmicpc.net/problem/10990

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10990
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		for1(i, n)
		{
			// n-i-1
			for1(j, n - i - 1)
			{
				cout << " ";
			}
			cout << "*";

			if (i > 0)
			{
				// 2i-1
				for1(j, 2 * i - 1)
				{
					cout << " ";
				}
				cout << "*";
			}

			if (i < n - 1)
			{
				cout << "\n";
			}
		}

		return 0;
	}
};