// https://www.acmicpc.net/problem/1783

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p13303
{
	long long pibo[80];
	long long getpibo(int i)
	{
		if (pibo[i] != 0)
			return pibo[i];

		return pibo[i] = getpibo(i - 1) + getpibo(i - 2);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		pibo[0] = 1;
		pibo[1] = 1;
		int n;
		cin >> n;

		n -= 1;
		if (n == 2)
		{
			cout << 2 * 3 + 1 * 4;
		}
		else if (n == 1)
		{
			cout << 1 * 6;
		}
		else if (n == 0)
		{
			cout << 1 * 4;
		}
		else
		{
			// 3 2 2 1
			cout << getpibo(n) * 3 + getpibo(n - 1) * 2
				+ getpibo(n - 2) * 2 + getpibo(n - 3) * 1;
		}

		return 0;
	}
};