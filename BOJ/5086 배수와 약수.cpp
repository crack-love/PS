// https://www.acmicpc.net/problem/5086

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p5086
{
	int main()
	{
		while (true)
		{
			int a, b;
			cin >> a >> b;
			if (a == 0 && b == 0) break;

			if (b % a == 0)
			{
				cout << "factor\n";
			}
			else if (a % b == 0)
			{
				cout << "multiple\n";
			}
			else
			{
				cout << "neither\n";
			}
		}

		return 0;
	}
};