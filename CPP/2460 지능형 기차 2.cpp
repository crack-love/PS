// https://www.acmicpc.net/problem/2460

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2460
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int sum = 0;
		int answer = 0;
		for (int i = 0; i < 10; ++i)
		{
			int a, b;
			cin >> a >> b;
			sum -= a;
			sum += b;
			answer = max(answer, sum);
		}
		cout << answer;
		return 0;
	}
};