// https://www.acmicpc.net/problem/10815

#include <iostream>
#include <algorithm>
using namespace std;

struct p10815
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int cards[500000];
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
			if (l == cards + n)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << (*l == x) << " ";
			}
		}

		return 0;
	}
};