// https://www.acmicpc.net/problem/3036

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p3036
{
	int gcd(int a, int b)
	{
		if (b == 0)
		{
			return a;
		}
		return gcd(b, a % b);
	}

	void print(int a, int x)
	{
		int g = a < x ? gcd(x, a) : gcd(a, x);
		cout << a / g << "/" << x / g << "\n";
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int a;
		cin >> a;
		for (int i = 0; i < n - 1; ++i)
		{
			int x;
			cin >> x;
			print(a, x);
		}

		return 0;
	}
};