// https://www.acmicpc.net/problem/9610

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p9610
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
		int axis = 0;
		int n;
		cin >> n;
		for1(i, n)
		{
			int x, y;
			cin >> x >> y;
			if (x == 0 || y == 0)
			{
				axis += 1;
			}
			else if (x < 0)
			{
				if (y < 0)
				{
					q3 += 1;
				}
				else if (y > 0)
				{
					q2 += 1;
				}
			}
			else if (x > 0)
			{
				if (y < 0)
				{
					q4 += 1;
				}
				else if (y > 0)
				{
					q1 += 1;
				}
			}
		}

		cout << "Q1: " << q1 << "\n";
		cout << "Q2: " << q2 << "\n";
		cout << "Q3: " << q3 << "\n";
		cout << "Q4: " << q4 << "\n";
		cout << "AXIS: " << axis << "\n";

		return 0;
	}
};