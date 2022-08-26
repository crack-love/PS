// https://www.acmicpc.net/problem/3003

#include <bits/stdc++.h>
using namespace std;

struct p3003
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int max[6] = { 1, 1, 2, 2, 2, 8 };
		for (int i = 0; i < 6; ++i)
		{
			int x;
			cin >> x;
			cout << max[i] - x << " ";
		}

		return 0;
	}
};