// https://www.acmicpc.net/problem/1111

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

int main()
{
	fastio;

	int n;
	cin >> n;
	int x[50];
	for1(i, n)
	{
		cin >> x[i];
	}

	// n == 1
	// x0a + b = inf
	if (n == 1)
	{
		cout << "A";
		return 0;
	}

	// n == 2
	// x0a + b = x1
	// x1a + b = x2
	// (x0-x1)a = x1-x2
	if (n == 2)
	{
		if (x[0] == x[1])
		{
			cout << x[1];
		}
		else
		{
			cout << "A";
		}
		return 0;
	}

	// n >= 3
	// x0a + b = x1
	// x1a + b = x2
	// (x0-x1)a = x1 - x2
	// a = (x1 - x2) / (x0 - x1)
	// 
	// find a range
	// -> for min a, xs = 99 100 -100, a = -200
	// -> for max a, xs = 100 99 -100, a = 199
	// 
	// find b range
	// (-100~100)*(-200~199) + b = (-100~100)
	// b = (-100~100) - (-100~100)*(-200~199)
	// -> min b = -100 - 100 * 199 = -20000
	// -> max b = 100 - 100 * -200 = 20100
	//
	// if x0 == x1
	// x0a + b = x0
	// x0a + b = x2
	// -> xs = x0, x0, x0..
	if (x[0] == x[1])
	{
		bool fail = false;
		for (int i = 2; i < n; ++i)
		{
			if (x[i] != x[0])
			{
				fail = true;
				break;
			}
		}
		if (fail)
		{
			cout << "B";
		}
		else
		{
			cout << x[0];
		}
		return 0;
	}
	// if x1 == x2
	// x0a + b = x1
	// x1a + b = x1
	// (x0-x1)a = 0
	// -> a = 0, xs = ? x1 x1 x1...
	if (x[1] == x[2])
	{
		bool fail = false;
		for (int i = 3; i < n; ++i)
		{
			if (x[i] != x[1])
			{
				fail = true;
				break;
			}
		}

		if (fail)
		{
			cout << "B";
		}
		else
		{
			cout << x[1];
		}
		return 0;
	}

	set<int> ans;
	for (int a = -200; a <= 199; ++a)
	{
		for (int b = -20000; b <= 20100; ++b)
		{
			bool fail = false;
			for (int i = 0; i < n - 1; ++i)
			{
				if (x[i] * a + b != x[i + 1])
				{
					fail = true;
					break;
				}
			}

			if (!fail)
			{
				int nv = x[n - 1] * a + b;
				ans.insert(nv);
				if (ans.size() > 1)
				{
					break;
				}
			}
		}
	}

	if (ans.size() > 1)
	{
		cout << "A";
	}
	else if (ans.size() == 0)
	{
		cout << "B";
	}
	else
	{
		cout << *ans.begin();
	}

	return 0;
}