// https://www.acmicpc.net/problem/3135

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p3135
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b;
		cin >> a >> b;
		int n;
		cin >> n;

		int arr[5];
		for1(i, n)
		{
			cin >> arr[i];
		}

		int ans = 0;
		// 처음부터 목적지
		ans = abs(b - a);
		// 즐겨찾기 이동 후 목적지
		for1(i, n)
		{
			int v = abs(arr[i] - b) + 1;
			ans = min(ans, v);
		}

		cout << ans;
		return 0;
	}
};