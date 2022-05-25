// https://www.acmicpc.net/problem/15650

#include <iostream>
#include <vector>
using namespace std;

struct p15650
{
	int n;
	vector<int> nums;

	void push(int m)
	{
		if (m <= 0)
		{
			for (int i = 1; i < nums.size(); ++i)
			{
				cout << nums[i] << " ";
			}
			cout << "\n";
			return;
		}

		for (int i = nums.back() + 1; i <= n; ++i)
		{
			nums.push_back(i);
			push(m - 1);
			nums.pop_back();
		}
	}

	int main()
	{
		int m;
		cin >> n >> m;

		nums.push_back(0);
		push(m);

		return 0;
	}
};