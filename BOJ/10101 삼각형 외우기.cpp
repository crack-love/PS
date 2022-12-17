// https://www.acmicpc.net/problem/10101

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10101
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b, c;
		cin >> a >> b >> c;
		if (a == 60 && b == 60 && c == 60)
		{
			cout << "Equilateral";
		}
		else if (a + b + c == 180)
		{
			if (a == b || b == c || a == c)
			{
				cout << "Isosceles";
			}
			else
			{
				cout << "Scalene";
			}
		}
		else
		{
			cout << "Error";
		}

		return 0;
	}
};