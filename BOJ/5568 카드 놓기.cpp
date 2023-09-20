// https://www.acmicpc.net/problem/5568

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p5568
{
	int n, k;
	int a[10];
	unordered_set<int> s;

	void perm(int cnt, int val, int bit)
	{
		if (cnt >= k)
		{
			s.insert(val);
			return;
		}

		for1(i, n)
		{
			if (bit & (1 << i)) continue;

			int nv = val;
			nv *= a[i] >= 10 ? 100 : 10;
			nv += a[i];

			perm(cnt + 1, nv, bit | (1 << i));
		}
	}

	int main()
	{
		fastio;

		cin >> n >> k;
		for1(i, n)
		{
			cin >> a[i];
		}

		perm(0, 0, 0);

		cout << s.size();
		return 0;
	}
};