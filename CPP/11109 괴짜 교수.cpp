// https://www.acmicpc.net/problem/11109

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p11109
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		while (t--)
		{
			int d, n, s, p;
			cin >> d >> n >> s >> p;
			ll sn = s * n;
			ll pn = d + n * p;
			if (sn < pn)
			{
				cout << "do not parallelize";
			}
			else if (sn > pn)
			{
				cout << "parallelize";
			}
			else
			{
				cout << "does not matter";
			}
			cout << "\n";
		}

		return 0;
	}
};