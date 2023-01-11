// https://www.acmicpc.net/problem/7785

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p7785
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		set<string, greater<string>> s;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			string name, op;
			cin >> name >> op;
			if (op[0] == 'e')
			{
				s.insert(name);
			}
			else if (op[0] == 'l')
			{
				s.erase(name);
			}
		}

		for (string k : s)
		{
			cout << k << "\n";
		}

		return 0;
	}
};