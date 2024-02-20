// https://www.acmicpc.net/problem/14501

#include <iostream>
using namespace std;

struct p14501
{
	int n;
	int t[15];
	int p[15];
	int answer = 0;

	void dfs(int i, int sum)
	{
		if (i >= n)
		{
			if (sum > answer)
			{
				answer = sum;
			}
			return;
		}

		if (i + t[i] <= n)
		{
			dfs(i + t[i], sum + p[i]);
		}

		dfs(i + 1, sum);
	}

	int main()
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> t[i] >> p[i];
		}

		dfs(0, 0);

		cout << answer;

		return 0;
	}
};