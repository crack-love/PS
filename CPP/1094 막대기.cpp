// https://www.acmicpc.net/problem/1094

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1094
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int x;
		cin >> x;
		vector<int> v;
		v.push_back(64);
		int sum = 64;

		while (sum != x)
		{
			int peek = v.back();
			v.pop_back();
			sum -= peek;

			if (peek / 2 == 0)
			{
				continue;
			}
			if (sum + peek / 2 >= x)
			{
				sum += peek / 2;
				v.push_back(peek / 2);
			}
			else
			{
				sum += peek;
				v.push_back(peek / 2);
				v.push_back(peek / 2);
			}
		}

		cout << v.size();
		return 0;
	}
};