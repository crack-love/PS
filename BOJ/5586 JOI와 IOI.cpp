// https://www.acmicpc.net/problem/5586

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5586
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string s;
		cin >> s;
		string joi = "JOI";
		string ioi = "IOI";

		int joicnt = 0;
		int ioicnt = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (i + joi.size() <= s.size())
			{
				bool joiok = true;
				for (int j = 0; j < joi.size(); ++j)
				{
					if (s[i + j] != joi[j])
					{
						joiok = false;
						break;
					}
				}
				joicnt += (joiok ? 1 : 0);
			}
			if (i + ioi.size() <= s.size())
			{
				bool ioiok = true;
				for (int j = 0; j < ioi.size(); ++j)
				{
					if (s[i + j] != ioi[j])
					{
						ioiok = false;
						break;
					}
				}
				ioicnt += (ioiok ? 1 : 0);
			}

		}

		cout << joicnt << endl;
		cout << ioicnt << endl;
		return 0;
	}
};