// https://www.acmicpc.net/problem/2523

#include <iostream>
using namespace std;

struct p2523
{
	int main()
	{
		ios::sync_with_stdio(0);
		cout.tie(0);

		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cout << "*";
			}
			cout << "\n";
		}

		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cout << "*";
			}
			cout << "\n";
		}

		return 0;
	}
};