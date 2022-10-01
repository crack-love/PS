// https://www.acmicpc.net/problem/1789

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1789
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		long long s;
		cin >> s;
		long long sum = 0;
		int i = 0;
		while (true)
		{
			if (sum + i == s)
			{
				cout << i;
				break;
			}
			else if (sum + i > s)
			{
				cout << i - 1;
				break;
			}
			else
			{
				sum += i;
				i += 1;
			}
		}

		return 0;
	}
};