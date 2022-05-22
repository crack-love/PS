// https://www.acmicpc.net/problem/1146
// platinum5

#include <iostream>
#include <cstring>
using namespace std;

int d[100][100] = {};
int MOD = 1e6;

// can use lcnt
int solve(int lcnt, int rcnt)
{
	if (lcnt == 0 && rcnt == 0)
		return 2;

	if (d[lcnt][rcnt] > -1) 
		return d[lcnt][rcnt];

	int sum = 0;
	for (int i = 0; i < lcnt; ++i)
	{ 
		// swap l/r
		sum += solve(rcnt + i, lcnt - 1 - i);
		sum %= MOD;
	}

	return d[lcnt][rcnt] = sum;
}

int p1149v1()
{
	int n; // [1 20]
	cin >> n;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	memset(d, -1, sizeof(d));

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer += solve(i, n - 1 - i);
		answer %= MOD;
	}

	cout << answer;
	return 0;
}