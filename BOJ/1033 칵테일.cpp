// https://www.acmicpc.net/problem/1033
// gold2

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

int main()
{
	// spanning tree
	// search to calc lcm, modify edge
	// feedback all registed nodes (search)

	// 착오
	// long long type 사용하지 않음

	ll n;
	ll node[10] = {};
	pair<ll, ll> e[10][10] = {};

	// input
	cin >> n;
	for (ll i = 0; i < n - 1; ++i)
	{
		ll a, b, p, q;
		cin >> a >> b >> p >> q;

		ll p_gcd = gcd(p, q);
		p /= p_gcd;
		q /= p_gcd;

		// a/b = p/q -> qa = pb
		e[a][b] = {p,q};
		e[b][a] = {q,p};
	}

	auto calcNodeLcm = [&](ll i) -> ll
	{
		ll res = 1;
		for (ll j = 0; j < n; ++j)
		{
			if (e[i][j].first > 0)
			{
				res = lcm(res, e[i][j].first);
			}
		}
		return res;
	};

	queue<ll> cq;
	queue<ll> fq;
	cq.push(0);
	ll visit = 1;
	while (!cq.empty())
	{
		// calc lcm
		ll c = cq.front(); cq.pop();
		ll clcm = calcNodeLcm(c);
		node[c] = clcm;

		// modify edge
		ll fvisit = 0;
		for (ll i = 0; i < n; ++i)
		{
			if (e[c][i].first <= 0) continue;

			ll div = clcm / e[c][i].first;
			e[c][i].first *= div;
			e[c][i].second *= div;
			e[i][c].first *= div;
			e[i][c].second *= div;

			if (visit & (1<<i))
			{
				fq.push(i);
				fvisit |= (1<<i);
			}
			else
			{
				cq.push(i);
				visit |= (1<<i);
			}
		}

		// feedback
		while (!fq.empty())
		{
			ll f = fq.front(); fq.pop();
			ll flcm = calcNodeLcm(f);
			if (node[f] == flcm) continue;
			node[f] = flcm;

			for (ll i = 0; i < n; ++i)
			{
				if (!(visit & (1 << i))) continue;
				if (fvisit & (1 << i)) continue;
				if (e[f][i].first <= 0) continue;

				ll div = flcm / e[f][i].first;
				e[f][i].first *= div;
				e[f][i].second *= div;
				e[i][f].first *= div;
				e[i][f].second *= div;
				fq.push(i);
				fvisit |= (1<<i);
			}
		}
	}

	for (ll i = 0; i < n; ++i)
	{
		cout << node[i] << " ";
	}

	return 0;
}