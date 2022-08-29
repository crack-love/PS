// https://www.acmicpc.net/problem/1041

#include <bits/stdc++.h>
using namespace std;

struct p1041
{
	// 보이는 개수 : 
	// - 주사위 1개만 있을 때 : 6
	// - 버텍스에 있을 때 : 3
	// - 엣지에 있을 때 : 2
	// - 페이스에 있을 때 : 1 
	// - (각각 바닥면이면 -1)
	// 주사위 구성 :
	// - 버텍스 8, (바닥면 4개)
	// - 엣지 12*(n-2), (바닥면 4*(n-2)개)
	// - 페이스 6*(n^2-(n-1)*4), (바닥면 1*__개)

	//   3
	// 4 0 1 5
	//   2
	const int otherSide[6] = { 5, 4, 3, 2, 1, 0 };
	int a[6];

	int minSum(int begidx, int idx, int remain)
	{
		if (remain == 0) return 0;
		if (remain == 1) return a[idx];

		int ret = (int)1e9;
		for (int i = 0; i < 6; ++i)
		{
			if (i == idx) continue;
			if (i == begidx) continue;
			if (i == otherSide[idx]) continue;
			if (i == otherSide[begidx]) continue;
			int ms = minSum(begidx, i, remain - 1) + a[idx];
			ret = min(ret, ms);
		}
		return ret;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		typedef long long ll;

		ll n;
		cin >> n;
		for (int i = 0; i < 6; ++i)
		{
			cin >> a[i];
		}

		vector<int> s(4, (int)1e9); // 0~3
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				int ms = minSum(j, j, i);
				if (s[i] > ms)
				{
					s[i] = ms;
				}
			}
		}

		ll sum = 0;
		if (n == 1)
		{
			sort(a, a + 6);
			for (int i = 0; i < 5; ++i)
			{
				sum += a[i];
			}
		}
		else
		{
			ll uv = 4;
			ll bv = 4;
			ll ue = 8 * (n - 2);
			ll be = 4 * (n - 2);
			ll uf = 5 * (n * n - (n - 1) * 4);
			ll bf = 1 * (n * n - (n - 1) * 4);

			sum += uv * s[3];
			sum += bv * s[2];
			sum += ue * s[2];
			sum += be * s[1];
			sum += uf * s[1];
			sum += bf * s[0];
		}

		cout << sum;
		return 0;
	}
};