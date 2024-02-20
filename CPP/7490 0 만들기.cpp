// https://www.acmicpc.net/problem/7490

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p7490
{
	int n;
	string h;
	void solve(int i, int v, int r, bool neg)
	{
		if (i == n - 1)
		{
			v += r * (neg ? -1 : 1);
			if (v == 0)
			{
				cout << h << "\n";
			}
			return;
		}

		int a = i + 2;

		h.push_back(' ');
		h.push_back(a + '0');
		solve(i + 1, v, r * 10 + a, neg);
		h.pop_back();
		h.pop_back();

		h.push_back('+');
		h.push_back(a + '0');
		solve(i + 1, v + r * (neg ? -1 : 1), a, false);
		h.pop_back();
		h.pop_back();

		h.push_back('-');
		h.push_back(a + '0');
		solve(i + 1, v + r * (neg ? -1 : 1), a, true);
		h.pop_back();
		h.pop_back();
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			cin >> n;
			h = "1";
			solve(0, 0, 1, false);
			cout << "\n";
		}

		return 0;
	}
};