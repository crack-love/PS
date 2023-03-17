// https://www.acmicpc.net/problem/1543

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1543
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string d;
		string w;
		getline(cin, d);
		getline(cin, w);

		int answer = 0;
		for1(i, d.size())
		{
			bool match = true;
			for1(j, w.size())
			{
				if (i + j >= d.size() || d[i + j] != w[j])
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				answer += 1;
				i += w.size() - 1;
			}
		}

		cout << answer;
		return 0;
	}
};