// https://www.acmicpc.net/problem/9613
// silver3

#include <iostream>
#include <vector>
using namespace std;

struct p9613
{
	int gcd(int a, int b)
	{
		if (a < b)
		{
			int t = a;
			a = b;
			b = t;
		}

		if (b == 0)
		{
			return a;
		}

		return gcd(b, a % b);
	}

	int main()
	{
		vector<int> v;

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;

			long long answer = 0;
			v.clear();
			for (int i = 0; i < n; ++i)
			{
				int x;
				cin >> x;
				v.push_back(x);

				for (int j = 0; j < i; ++j)
				{
					answer += gcd(x, v[j]);
				}
			}
			cout << answer << "\n";
		}
		return 0;
	}
};