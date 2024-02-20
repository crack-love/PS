// https://www.acmicpc.net/problem/11050

#include <iostream>
using namespace std;

struct p11050
{
	int fact(int x)
	{
		if (x <= 1) return 1;

		return x * fact(x - 1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, k;
		cin >> n >> k;

		cout << fact(n) / (fact(k) * fact(n - k));

		return 0;
	}
};