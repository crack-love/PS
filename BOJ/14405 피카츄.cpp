// https://www.acmicpc.net/problem/14405

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p14405
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;

		bool ok = true;
		for1(i, s.size())
		{
			if (i + 1 < s.size())
			{
				string ss = s.substr(i, 2);
				if (ss == "pi")
				{
					i += 1;
					continue;
				}
				else if (ss == "ka")
				{
					i += 1;
					continue;
				}
			}

			if (i + 2 < s.size())
			{
				string ss = s.substr(i, 3);
				if (ss == "chu")
				{
					i += 2;
					continue;
				}
			}

			ok = false;
			break;
		}

		cout << (ok ? "YES" : "NO");

		return 0;
	}
};