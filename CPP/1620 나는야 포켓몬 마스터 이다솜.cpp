// https://www.acmicpc.net/problem/1620

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1620
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string iton[(int)1e5 + 1];
		map<string, int> ntoi;

		int n, m;
		cin >> n >> m;
		string s;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			iton[i + 1] = s;
			ntoi.insert({ s, i + 1 });
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> s;
			if ('0' <= s[0] && s[0] <= '9')
			{
				int v = stoi(s);
				cout << iton[v] << "\n";
			}
			else
			{
				cout << ntoi[s] << "\n";
			}
		}

		return 0;
	}
};