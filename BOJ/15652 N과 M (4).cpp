// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <vector>
using namespace std;

struct p15652
{
	void solve(int idx, int n, int m, vector<int>& v)
	{
		if (idx == m)
		{
			for (int i : v)
			{
				cout << i << " ";
			}
			cout << "\n";
			return;
		}

		int i = 1;
		if (v.size() > 0)
		{
			i = v.back();
		}

		for (i; i <= n; ++i)
		{
			v.push_back(i);
			solve(idx + 1, n, m, v);
			v.pop_back();
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cout.tie(0);

		int n, m;
		cin >> n >> m;
		vector<int> v;
		solve(0, n, m, v);
		return 0;
	}
};