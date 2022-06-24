// https://www.acmicpc.net/problem/2869

#include <iostream>
using namespace std;

struct p2869
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int a, b, v;
		cin >> a >> b >> v;

		// (v / (a - b)) - a / (a - b)

		int dayMove = a - b;
		int maxDay = v / dayMove + 1;
		int disc = a / dayMove;
		int minDay = maxDay - disc - 2;
		while (minDay < maxDay)
		{
			if ((minDay - 1) * dayMove + a >= v)
			{
				break;
			}
			else
			{
				++minDay;
			}
		}
		cout << minDay;

		return 0;
	}
};