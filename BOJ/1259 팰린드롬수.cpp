// https://www.acmicpc.net/problem/1259

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p1259
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		string a;
		while (true)
		{
			cin >> a;
			if (a.size() == 1 && a[0] == '0') break;

			bool fail = false;
			for (int i = 0; i < a.size(); ++i)
			{
				if (a[i] != a[a.size() - i - 1])
				{
					fail = true;
					break;
				}
			}
			cout << (fail ? "no" : "yes") << "\n";
		}

		return 0;
	}
};