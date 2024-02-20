// https://www.acmicpc.net/problem/11670
// platinum4

#include <iostream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct p11670
{
	#define ll long long

	pair<ll, ll> ab[2500];
	unordered_set<int> edge[2500];
	unordered_map<ll, int> rtoi;
	unordered_map<int, ll> itor;
	int nextRIndex = 0;

	bool visited[2500];
	int par[7500];
	int child[2500];

	bool tryLink(int x)
	{
		visited[x] = true;
		for (int e : edge[x])
		{
			int p = par[e];
			if (p == -1 || (!visited[p] && tryLink(p)))
			{
				par[e] = x;
				child[x] = e;
				return true;
			}
		}
		return false;
	}

	int getRidx(ll r)
	{
		int idx;
		auto it = rtoi.find(r);
		if (it == rtoi.end())
		{
			idx = nextRIndex++;
			itor.insert({ idx, r });
			rtoi.insert({ r, idx });
		}
		else
		{
			idx = it->second;
		}
		return idx;
	}

	int main()
	{
		// a,b operator(+-*) -> result(ll)

		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int n; // [1 2500]
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			ll a, b;
			cin >> a >> b;
			ab[i].first = a;
			ab[i].second = b;

			ll r0 = a + b;
			ll r1 = a - b;
			ll r2 = a * b;
			int i0 = getRidx(r0);
			int i1 = getRidx(r1);
			int i2 = getRidx(r2);
			edge[i].insert({ i0, i1, i2 });
		}

		memset(par, -1, sizeof(int) * n * 3);

		int linked = 0;
		for (int i = 0; i < n; ++i)
		{
			memset(visited, 0, sizeof(bool) * n);
			if (tryLink(i))
			{
				++linked;
			}
		}

		// 최대 매칭이 안되면 impossible
		if (linked < n)
		{
			cout << "impossible";
			return 0;
		}

		for (int i = 0; i < n; ++i)
		{
			ll a = ab[i].first;
			ll b = ab[i].second;
			ll r = itor[child[i]];

			cout << a << " ";

			if (r == a + b)
				cout << "+ ";
			else if (r == a - b)
				cout << "- ";
			else if (r == a * b)
				cout << "* ";

			cout << b << " = " << r << "\n";
		}
	}
};