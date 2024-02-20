// https://www.acmicpc.net/problem/10812

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p10812
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		int arr0[101];
		int arr1[101];
		for1(i, n)
		{
			arr0[i + 1] = i + 1;
		}

		int* a0 = arr0;
		int* a1 = arr1;

		for1(i, m)
		{
			int b, e, m;
			cin >> b >> e >> m;

			int didx = b;
			for (int j = m; j <= e; ++j)
			{
				a1[didx++] = a0[j];
			}
			for (int j = b; j < m; ++j)
			{
				a1[didx++] = a0[j];
			}

			for (int j = 1; j < b; ++j)
			{
				a1[j] = a0[j];
			}
			for (int j = e + 1; j <= n; ++j)
			{
				a1[j] = a0[j];
			}

			swap(a0, a1);
		}

		for1(i, n)
		{
			cout << a0[i + 1] << " ";
		}

		return 0;
	}
};