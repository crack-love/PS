// https://www.acmicpc.net/problem/1039
// gold3

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct p1039
{
	bool canFlushK = false;
	string maxValue = "0";

	// dfs
	void solve(string& n, int i, int k)
	{
		// finish
		if (i >= n.size() - 1 || k <= 0)
		{
			// flush k
			if (k % 2 == 0 && canFlushK)
			{
				k = 0;
			}

			if (k <= 0 && n > maxValue)
			{
				maxValue = n;
			}

			return;
		}

		// noswap
		solve(n, i + 1, k);

		for (int j = i + 1; j < n.size(); ++j)
		{
			if (i == 0 && n[j] == '0') continue;

			// swap
			swap(n[i], n[j]);
			solve(n, i + 1, k - 1);
			swap(n[i], n[j]);
		}
	}

	int main()
	{
		// 착오: 플러쉬 가능한 조건을 명확하게 하지 않았음

		string n;
		int k;
		cin >> n >> k;

		// check can flush k
		if (n.size() > 2)
		{
			canFlushK |= true;
		}
		if (n.size() == 2)
		{
			canFlushK |= (n[0] != '0' && n[1] != '0');
		}

		solve(n, 0, k);

		if (maxValue == "0")
		{
			cout << "-1\n";
		}
		else
		{
			cout << maxValue << "\n";
		}

		return 0;
	}
};