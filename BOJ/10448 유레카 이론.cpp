// https://www.acmicpc.net/problem/10448

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p10448
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		vector<int> tris;
		int i = 1;
		int s = 0;
		while (true)
		{
			s += i;
			if (s > 1000)
			{
				break;
			}

			tris.push_back(s);
			i += 1;
		}

		unordered_set<int> h;
		for1(i, tris.size())
		{
			for1(j, tris.size())
			{
				for1(k, tris.size())
				{
					int v = tris[i] + tris[j] + tris[k];
					auto it = h.find(v);
					if (it == h.end())
					{
						h.insert(it, v);
					}
				}
			}
		}

		int t;
		cin >> t;
		while (t--)
		{
			int k;
			cin >> k;

			auto it = h.find(k);
			if (it == h.end())
			{
				cout << "0\n";
			}
			else
			{
				cout << "1\n";
			}
		}

		return 0;
	}
};