// https://www.acmicpc.net/problem/15651

#include <iostream>
#include <vector>
using namespace std;

struct p15651
{
	void print(int n, int m, int idx, vector<int>& v)
	{
		if (idx == m)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i] << " ";
			}
			cout << "\n";
			return;
		}

		for (int i = 1; i <= n; ++i)
		{
			v.push_back(i);
			print(n, m, idx + 1, v);
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
		print(n, m, 0, v);
		return 0;
	}
};