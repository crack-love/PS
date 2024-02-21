// https://www.acmicpc.net/problem/1024

#include <iostream>
using namespace std;

#define ll long long

struct p1024
{
	void main()
	{
		// 1. bsearch pivot에서 시작하여 길이가 y
		// 2. 결과 없으면 ++y (1~100)

		// x에서 시작하여 길이가 y인 수열의 합
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

	// 다른 방법
	// n에서 길이가 i(1~)인 수열의 합을 뺐을 때
	// i로 나눠지면 그 값이 시작값
};