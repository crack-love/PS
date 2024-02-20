// https://www.acmicpc.net/problem/2285
// gold4

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define ll long long

struct p2285
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		pair<ll, ll> v[100000] = {};

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int x, a;
			cin >> x >> a;
			v[i] = { x,a };
		}
		sort(v, v + n);

		// curr pos = 0 idx
		ll lsum = 0;
		ll rsum = 0;
		for (int i = n - 1; i >= 1; --i)
		{
			rsum += v[i].second;
		}

		int ans = 0;
		ll ansDiff = rsum;
		for (int i = 1; i < n; ++i)
		{
			lsum += v[i - 1].second;
			rsum -= v[i].second;
			ll diff = abs(lsum - rsum);
			if (diff < ansDiff)
			{
				ans = i;
				ansDiff = diff;
			}
		}

		cout << v[ans].first;
		return 0;
	}
};