// https://www.acmicpc.net/problem/5800

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p5800
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int k;
		cin >> k;
		for1(i, k)
		{
			int n;
			cin >> n;
			int a[50];
			for1(j, n)
			{
				cin >> a[j];
			}

			sort(a, a + n);
			int lg = 0;
			for1(j, n)
			{
				if (j + 1 < n && a[j + 1] - a[j] > lg)
				{
					lg = a[j + 1] - a[j];
				}
			}

			cout << "Class " << (i + 1) << "\n";
			cout << "Max " << a[n - 1] << ", ";
			cout << "Min " << a[0] << ", ";
			cout << "Largest gap " << lg << "\n";
		}

		return 0;
	}
};