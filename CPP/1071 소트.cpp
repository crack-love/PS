// https://www.acmicpc.net/problem/1071
// platinum5

#include <iostream>
#include <algorithm>
using namespace std;

int p1071()
{
	// sort
	// from beg, swap back unfits
	// if fail, to left

	int n;
	int a[50] = {};
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] + 1 == a[i + 1])
		{
			// find best place
			bool found = false;
			for (int j = i + 2; j < n; ++j)
			{
				if (a[j] <= a[i + 1]) continue;
				else 
				{
					swap(a[j], a[i + 1]);
					found = true;
					break;
				}
			}

			// find fail
			if (!found)
			{
				swap(a[i], a[i + 1]);
			}

			// restart
			i = -1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}