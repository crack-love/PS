// https://www.acmicpc.net/problem/1158

#include <iostream>
#include <vector>
using namespace std;

struct p1158
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, k;
		cin >> n >> k;

		vector<int> arr;
		for (int i = 0; i < n; ++i)
		{
			arr.push_back(i + 1);
		}

		cout << "<";
		int cidx = -1;
		for (int i = 0; i < n; ++i)
		{
			cidx = (cidx + k) % arr.size();
			auto it = arr.begin() + cidx;

			cout << *it;
			if (i != n - 1) cout << ", ";

			arr.erase(it);
			cidx -= 1;
		}
		cout << ">";

		return 0;
	}
};