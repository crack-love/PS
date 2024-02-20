// https://www.acmicpc.net/problem/10102

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10102
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int v;
		cin >> v;
		string s;
		cin >> s;
		int a = 0;
		int b = 0;
		for1(i, s.size())
		{
			if (s[i] == 'A')
			{
				a += 1;
			}
			else if (s[i] == 'B')
			{
				b += 1;
			}
		}

		if (a == b)
		{
			cout << "Tie";
		}
		else if (a > b)
		{
			cout << "A";
		}
		else
		{
			cout << "B";
		}
		return 0;
	}
};