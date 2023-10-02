// https://www.acmicpc.net/problem/11723

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p11723
{
	int main()
	{
		fastio;

		int s = 0;
		int m;
		cin >> m;
		while (m--)
		{
			string o;
			cin >> o;
			int v;

			if (o[0] == 'a')
			{
				if (o[1] == 'd')
				{
					cin >> v;
					s |= 1 << v;
				}
				else if (o[1] == 'l')
				{
					s = ~0;
				}
			}
			else if (o[0] == 'r')
			{
				cin >> v;
				s &= ~(1 << v);
			}
			else if (o[0] == 'c')
			{
				cin >> v;
				cout << ((s & (1 << v)) ? 1 : 0) << "\n";
			}
			else if (o[0] == 't')
			{
				cin >> v;
				s ^= (1 << v);
			}
			else if (o[0] == 'e')
			{
				s = 0;
			}
		}

		return 0;
	}
};