// https://www.acmicpc.net/problem/1456

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1456
{
	int main()
	{
		fastio;

		ll a, b;
		cin >> a >> b;

		int cap = sqrt(b);
		bool isNotPrime[(int)1e7 + 1]{};
		vector<int> prime;
		for (int i = 2; i <= cap; ++i)
		{
			if (!isNotPrime[i])
			{
				prime.push_back(i);
				for (int j = i + i; j <= cap; j += i)
				{
					isNotPrime[j] = true;
				}
			}
		}

		int ans = 0;
		for (int p : prime)
		{
			for (double np = (double)p * p; np <= b; np *= p)
			{
				if (np < a)
					continue;

				ans += 1;
			}
		}

		cout << ans;
		return 0;
	}
};