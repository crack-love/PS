// https://www.acmicpc.net/problem/2798

#include <iostream>
using namespace std;

struct p2798
{
	int main()
	{
		int arr[100];
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		int maxval = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				for (int k = j + 1; k < n; ++k)
				{
					int sum = arr[i] + arr[j] + arr[k];
					if (sum > maxval && sum <= m)
					{
						maxval = sum;
					}
				}
			}
		}

		cout << maxval;

		return 0;
	}
};