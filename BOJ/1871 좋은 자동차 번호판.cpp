// https://www.acmicpc.net/problem/1871

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1871
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		while (n--)
		{
			string line;
			cin >> line;

			int v0 = 0;
			int lv = 1;
			v0 += (line[2] - 'A') * lv;
			lv *= 26;
			v0 += (line[1] - 'A') * lv;
			lv *= 26;
			v0 += (line[0] - 'A') * lv;

			string s = line.substr(4);
			int v1 = stoi(s);
			if (abs(v0 - v1) > 100)
			{
				cout << "not nice" << "\n";
			}
			else
			{
				cout << "nice\n";
			}
		}

		return 0;
	}
};