// https://www.acmicpc.net/problem/14696

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p14696
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		while (n--)
		{
			int a;
			cin >> a;
			int av[100];
			for1(i, a)
			{
				cin >> av[i];
			}

			int b, bv[100];
			cin >> b;
			for1(i, b)
			{
				cin >> bv[i];
			}

			sort(av, av + a, greater<int>());
			sort(bv, bv + b, greater<int>());

			bool finished = false;
			for (int i = 0; i < a && i < b; ++i)
			{
				if (av[i] > bv[i])
				{
					cout << "A";
					finished = true;
					break;
				}
				else if (av[i] < bv[i])
				{
					cout << "B";
					finished = true;
					break;
				}
			}

			if (!finished)
			{
				if (a > b)
				{
					cout << "A";
				}
				else if (b > a)
				{
					cout << "B";
				}
				else
				{
					cout << "D";
				}
			}
			cout << "\n";
		}

		return 0;
	}
};