// https://www.acmicpc.net/problem/10988

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10988
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;
		int a = 0, b = s.size() - 1;
		while (a <= b)
		{
			if (s[a] != s[b])
			{
				cout << 0;
				return 0;
			}
			a += 1;
			b -= 1;
		}

		cout << 1;
		return 0;
	}
};