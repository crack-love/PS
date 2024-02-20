// https://www.acmicpc.net/problem/1644

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1644
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<int> prims;
		const int netSize = (int)4e6;
		bool net[netSize + 1]{};
		for (int i = 2; i <= netSize; ++i)
		{
			if (!net[i])
			{
				prims.push_back(i);

				for (int j = i; j <= netSize; j += i)
				{
					net[j] = true;
				}
			}
		}

		int n;
		int answer = 0;
		cin >> n;
		int sum = 0;
		int left = 0;
		for (int i = 0; i < prims.size() && prims[i] <= n; ++i)
		{
			sum += prims[i];

			while (sum >= n)
			{
				if (sum == n)
				{
					answer += 1;
				}

				sum -= prims[left];
				left += 1;
			}
		}

		cout << answer;

		return 0;
	}
};