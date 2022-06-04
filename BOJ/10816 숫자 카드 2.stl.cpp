// https://www.acmicpc.net/problem/10816
// silver4

#include <iostream>
#include <algorithm>
using namespace std;

struct p10816_stl
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int cards[500000] = {};
		int n, m;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> cards[i];
		}

		sort(cards, cards + n);

		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int x;
			cin >> x;

			int* l = lower_bound(cards, cards + n, x);
			int* r = upper_bound(cards, cards + n, x);
			cout << r - l << " ";
		}

		return 0;
	}
};