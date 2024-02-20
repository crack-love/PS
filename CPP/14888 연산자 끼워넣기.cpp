// https://www.acmicpc.net/problem/14888

#include <iostream>
using namespace std;

struct p14888
{
	int n;
	int nums[11];
	int operCnt[4];
	int maxVal = (int)-1e9 - 1;
	int minVal = (int)1e9 + 1;

	void brute(int idx, int value)
	{
		if (idx == n)
		{
			if (value > maxVal) maxVal = value;
			if (value < minVal) minVal = value;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			if (operCnt[i] > 0)
			{
				operCnt[i] -= 1;

				switch (i)
				{
				case 0:	brute(idx + 1, value + nums[idx]); break;
				case 1:	brute(idx + 1, value - nums[idx]); break;
				case 2:	brute(idx + 1, value * nums[idx]); break;
				case 3:	brute(idx + 1, value / nums[idx]); break;
				}

				operCnt[i] += 1;
			}
		}
	}

	int main()
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		for (int i = 0; i < 4; ++i)
		{
			cin >> operCnt[i];
		}

		brute(1, nums[0]);

		cout << maxVal << "\n";
		cout << minVal << "\n";
		return 0;
	}
};