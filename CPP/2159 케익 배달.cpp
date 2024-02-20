// https://www.acmicpc.net/problem/2159
// gold2

#include <iostream>
using namespace std;

#define ll long long
#define min(a,b) (a<b?a:b)

struct p2159
{
	const int dx[5] = { 0, 1, -1, 0, 0 };
	const int dy[5] = { 0, 0, 0, 1, -1 };

	int px[100001] = {};
	int py[100001] = {};
	ll d[100001][5] = {};
	// dij = min di-1j0..4 + dist

	int distance(int i, int ik, int j, int jk)
	{
		if (i == 0) ik = 0; // start pos constraint
		int xdis = abs((px[i] + dx[ik]) - (px[j] + dx[jk]));
		int ydis = abs((py[i] + dy[ik]) - (py[j] + dy[jk]));
		return xdis + ydis;
	}

	ll dp(int i, int j)
	{
		if (i <= 0) return 0;
		if (d[i][j] != 0) return d[i][j];

		ll res = 0;
		for (int k = 0; k < 5; ++k)
		{
			ll v = dp(i - 1, k) + (ll)distance(i - 1, k, i, j);
			if (k == 0) res = v;
			else res = min(res, v);
		}
		return d[i][j] = res;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int n;
		cin >> n >> px[0] >> py[0];
		for (int i = 1; i <= n; ++i)
		{
			cin >> px[i] >> py[i];
		}

		ll answer = dp(n, 0);
		for (int i = 1; i < 5; ++i)
		{
			ll v = dp(n, i);
			answer = min(answer, v);
		}
		cout << answer;
		return 0;
	}
};