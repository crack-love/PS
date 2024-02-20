// https://www.acmicpc.net/problem/3053

#include <bits/stdc++.h>
using namespace std;

struct p3053
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		double pi = 3.141592653589793238462643383279502884197169399375105820974944;
		int r;
		cin >> r;

		cout.setf(cout.fixed);
		cout.precision(4);
		cout << pi * (r * r) << "\n";
		cout << (double)2 * r * r;

		return 0;
	}
};