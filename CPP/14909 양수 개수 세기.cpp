// https://www.acmicpc.net/problem/14909

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p14909
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string line;
		getline(cin, line);
		int ans = 0;
		for (int i = 0; i < line.size(); ++i)
		{
			int j = line.find_first_of(' ', i + 1);
			if (j == -1)
			{
				j = line.size();
			}

			if (j == i + 1 && line[i] == '0')
			{

			}
			else if (line[i] == '-')
			{

			}
			else
			{
				ans += 1;
			}

			i = j;
		}

		cout << ans;
		return 0;
	}
};