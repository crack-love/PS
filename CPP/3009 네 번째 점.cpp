// https://www.acmicpc.net/problem/3009

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct p3009
{
	int main()
	{
		vector<int> xs;
		vector<int> ys;

		for (int i = 0; i < 3; ++i)
		{
			int x, y;
			cin >> x >> y;

			auto xit = find(xs.begin(), xs.end(), x);
			auto yit = find(ys.begin(), ys.end(), y);

			if (xit != xs.end())
			{
				xs.erase(xit);
			}
			else
			{
				xs.push_back(x);
			}

			if (yit != ys.end())
			{
				ys.erase(yit);
			}
			else
			{
				ys.push_back(y);
			}
		}

		cout << *xs.begin() << " " << *ys.begin();
		return 0;
	}
};