// https://www.acmicpc.net/problem/28295

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p28295
{
	int main()
	{
		fastio;

		int dir = 0;
		for1(i, 10)
		{
			int x;
			cin >> x;
			if (x == 1)
			{
				dir += 1;
				dir %= 4;
			}
			else if (x == 2)
			{
				dir += 2;
				dir %= 4;
			}
			else if (x == 3)
			{
				dir = dir + 4 - 1;
				dir %= 4;
			}
		}

		cout << (dir == 0 ? "N" : (dir == 1 ? "E" : (dir == 2 ? "S" : "W")));
		return 0;
	}
};