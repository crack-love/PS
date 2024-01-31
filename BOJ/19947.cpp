// https://www.acmicpc.net/problem/19947

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p19947
{
	int main()
	{
		fastio;

		int h, y;
		cin >> h >> y;
		int a[11]{ h };

		for (int i = 0; i < y + 1; ++i)
		{
			if (i + 1 <= y)
				a[i + 1] = max(a[i + 1], (int)(a[i] * 1.05));
			if (i + 3 <= y)
				a[i + 3] = max(a[i + 3], (int)(a[i] * 1.2));
			if (i + 5 <= y)
				a[i + 5] = max(a[i + 5], (int)(a[i] * 1.35));
		}

		cout << a[y];

		return 0;
	}
};