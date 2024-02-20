// https://www.acmicpc.net/problem/8979

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p8979
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;
		tuple<int, int, int, int> a[1001];
		for1(i, n)
		{
			int idx, x, y, z;
			cin >> idx >> x >> y >> z;
			a[idx] = { x, y, z, idx };
		}

		sort(a, a + (n + 1), greater<tuple<int, int, int, int>>());

		int rank = 0;
		int stack = 0;
		int px = INT_MIN, py = INT_MIN, pz = INT_MIN;
		for1(i, n)
		{
			auto [x, y, z, idx] = a[i];

			if (x != px || y != py || z != pz)
			{
				px = x;
				py = y;
				pz = z;
				rank += stack + 1;
				stack = 0;
			}
			else if (x == px && y == py && z == pz)
			{
				stack += 1;
			}

			if (idx == k)
			{
				cout << rank;
				break;
			}
		}

		return 0;
	}
};