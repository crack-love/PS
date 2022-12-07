// https://www.acmicpc.net/problem/2559

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2559
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;
		int a[100000];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		int sum = 0;
		for (int i = 0; i < k; ++i)
		{
			sum += a[i];
		}

		int answer = sum;
		for (int i = 0; i < n; ++i)
		{
			int r = i + k;
			if (r >= n) break;
			sum -= a[i];
			sum += a[r];
			answer = max(answer, sum);
		}
		cout << answer;
		return 0;
	}
};