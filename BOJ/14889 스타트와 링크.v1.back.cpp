// https://www.acmicpc.net/problem/14889

#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];
vector<int> pickeds;
int answer = 1e9;

void pick(int i, int lsum, int rsum)
{
	if (i >= n)
	{
		answer = min(answer, abs(lsum - rsum));
		return;
	}

	if (pickeds.size() + (n - i) >= n / 2)
	{
		int isum = 0;
		for (int p : pickeds) 
		{
			isum += a[p][i] + a[i][p];
		}

		pickeds.push_back(i);
		pick(i + 1, lsum + isum, rsum - isum);
		pickeds.pop_back();
	}
	
	pick(i + 1, lsum, rsum);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			sum += a[i][j] + a[j][i];
		}
	}

	pick(0, 0, sum);
	cout << answer;
	return 0;
}