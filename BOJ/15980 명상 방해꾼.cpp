// https://www.acmicpc.net/problem/15980

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p15980
{
	int main()
	{
		fastio;

		int n, m;
		cin >> n >> m;
		pair<int, string> bs[2000];
		for1(i, n)
		{
			char c;
			string s;
			cin >> c >> s;
			bs[i] = { c == 'L' ? -1 : 1, s };
		}

		int sum[2000]{};
		for1(i, m)
		{
			if (i > 0)
				sum[i] = sum[i - 1];

			for1(j, n)
			{
				int v = (bs[j].second[i] == '1' ? 1 : 0) * bs[j].first;
				sum[i] += v;
			}
		}

		int ansbird = 0;
		int ansmaxv = 4000001;
		for1(i, n) // kill
		{
			int maxv = 0;
			int offset = 0;
			for1(j, m)
			{
				int v = (bs[i].second[j] == '1' ? 1 : 0) * bs[i].first;
				offset -= v;
				maxv = max(abs(sum[j] + offset), maxv);
			}

			if (maxv < ansmaxv)
			{
				ansbird = i;
				ansmaxv = maxv;
			}
		}

		cout << ansbird + 1 << "\n" << ansmaxv;
		return 0;
	}
};