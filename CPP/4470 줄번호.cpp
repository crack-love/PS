// https://www.acmicpc.net/problem/4470

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p4470
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		for1(i, n)
		{
			string s;
			getline(cin, s);
			if (s.empty())
			{
				i -= 1;
				continue;
			}

			cout << (i + 1) << ". " << s << "\n";
		}

		return 0;
	}
};