// https://www.acmicpc.net/problem/10816
// silver4

#include <iostream>
#include <algorithm>
using namespace std;

struct p10816_imp
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

			int lowerBound = n;
			int l = 0;
			int r = n;
			while (l < r)
			{
				int m = (l + r) / 2;
				int mv = cards[m];

				if (mv < x)
				{
					l = m + 1;
				}
				else if (mv > x)
				{
					r = m;
				}
				else if (mv == x)
				{
					lowerBound = m;
					r = m;
				}
			}

			int upperBound = n;
			l = 0;
			r = n;
			while (l < r)
			{
				int m = (l + r) / 2;
				int mv = cards[m];

				if (mv < x)
				{
					l = m + 1;
				}
				else if (mv > x)
				{
					r = m;
				}
				else if (mv == x)
				{
					upperBound = m + 1;
					l = m + 1;
				}
			}

			cout << upperBound - lowerBound << " ";
		}

		return 0;
	}
};