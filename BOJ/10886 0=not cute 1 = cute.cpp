// https://www.acmicpc.net/problem/10886

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10886
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int a = 0, b = 0;
		while (n--)
		{
			int x;
			cin >> x;
			if (x == 0)
			{
				a += 1;
			}
			else
			{
				b += 1;
			}
		}

		if (a > b)
		{
			cout << "Junhee is not cute!";
		}
		else
		{
			cout << "Junhee is cute!";
		}

		return 0;
	}
};