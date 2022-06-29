// https://www.acmicpc.net/problem/5543

#include <iostream>
using namespace std;

struct p5543
{
	int main()
	{
		int minFood = 2000;
		int minBeve = 2000;
		for (int i = 0; i < 3; ++i)
		{
			int x;
			cin >> x;
			if (x < minFood) minFood = x;
		}
		for (int i = 0; i < 2; ++i)
		{
			int x;
			cin >> x;
			if (x < minBeve) minBeve = x;
		}

		cout << minFood + minBeve - 50;

		return 0;
	}
};