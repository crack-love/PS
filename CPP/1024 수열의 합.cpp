// https://www.acmicpc.net/problem/1024

#include <iostream>
using namespace std;

#define ll long long

struct p1024
{
	void main()
	{
		// 1. bsearch pivot���� �����Ͽ� ���̰� y
		// 2. ��� ������ ++y (1~100)

		// x���� �����Ͽ� ���̰� y�� ������ ��
		auto getSumValue = [](ll x, ll y) -> ll
		{
			if (y % 2 == 0) return (x + x + y - 1) * y / 2;
			if (y % 2 == 1) return (x + x + y) * (y + 1) / 2 - (x + y);
			return 0ll;
		};

		ll n, l;
		cin >> n >> l;

		int ansBeg = -1;
		int ansLen = -1;

		for (int len = (int)l; len <= 100; ++len)
		{
			int left = 0;
			int right = (int)(1e9 + 1);

			while (left < right)
			{
				int pivot = (left + right) / 2;

				ll sv = getSumValue(pivot, len);

				// found answer
				if (sv == n)
				{
					ansBeg = pivot;
					ansLen = len;
					len = 101;
					break;
				}
				// to right
				else if (sv < n)
				{
					left = pivot + 1;
				}
				// to left
				else
				{
					right = pivot;
				}
			}
		}

		// print
		if (ansBeg < 0)
		{
			cout << "-1\n";
		}
		else
		{
			for (int i = 0; i < ansLen; ++i)
			{
				if (i != 0) cout << " ";
				cout << ansBeg++;
			}
			cout << "\n";
		}
	}

	// �ٸ� ���
	// n���� ���̰� i(1~)�� ������ ���� ���� ��
	// i�� �������� �� ���� ���۰�
};