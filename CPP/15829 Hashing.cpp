// https://www.acmicpc.net/problem/15829

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p15829
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int l;
		cin >> l;
		string s;
		cin >> s;

		long long h = 0;
		const int mod = 1234567891;
		for (int i = 0; i < l; ++i)
		{
			long long add = s[i] - 'a' + 1;
			for (int j = 0; j < i; ++j)
			{
				add *= 31;
				add %= mod;
			}
			h += add;
			h %= mod;
		}

		cout << h;
		return 0;
	}
};