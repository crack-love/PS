// https://www.acmicpc.net/problem/7453
// gold2

#include <iostream>
#include <algorithm>
using namespace std;

struct p7453_fast
{
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[4][4000];
	int s[2][16000000];
	int n; // [1 4k]
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> a[j][i];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			s[0][i * n + j] = a[0][i] + a[1][j];
			s[1][i * n + j] = a[2][i] + a[3][j];
		}
	}

	const int n2 = n * n;
	sort(&s[0][0], &s[0][n2]);
	sort(&s[1][0], &s[1][n2], greater<>());

	long long answer = 0;
	int l = 0;
	int r = 0;
	while (l < n2 && r < n2 )
	{
		int sum = s[0][l] + s[1][r];

		if (sum < 0)
		{
			++l;
		}
		else if (sum > 0)
		{
			++r;
		}
		else
		{
			int lc = 1;
			while (l + 1 < n2 && s[0][l] == s[0][l + 1])
			{
				++l;
				++lc;
			}

			int rc = 1;
			while (r + 1 < n2 && s[1][r] == s[1][r + 1])
			{
				++r;
				++rc;
			}
			++l;
			++r;

			answer += (long long)lc * rc;
		}
	}

	cout << answer;
	return 0;
}
};