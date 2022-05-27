// https://www.acmicpc.net/problem/1676
// silver4

#include <iostream>
#include <vector>
using namespace std;

struct p1676
{
	// ÃÖ´ë 500¹ø °ö

	int main()
	{
		vector<int> num({1});

		int n;
		cin >> n;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = num.size() - 1; j >= 0; --j)
			{
				num[j] *= i;
			}

			for (int j = 0; j < num.size(); ++j)
			{
				int v = num[j];
				if (v >= 10)
				{
					if (j >= num.size() - 1)
					{
						num.push_back(0);
					}

					num[j + 1] += v / 10;
					num[j] = v % 10;
				}
			}
		}

		for (int i = 0; i < num.size(); ++i)
		{
			if (num[i] != 0)
			{
				cout << i;
				return 0;
			}
		}

		return 0;
	}
};

int main()
{
	p1676().main();
}