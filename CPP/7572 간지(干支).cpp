// https://www.acmicpc.net/problem/7572

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p7572
{
	int main()
	{
		fastio;

		int p0 = ('F' - 'A' - 2013 + 6000) % 12;
		int p1 = (9 - 2013 + 6000) % 10;
		int n;
		cin >> n;
		int a = (p0 + n) % 12;
		int b = (p1 + n) % 10;
		cout << (char)(a + 'A') << b;
		return 0;
	}
};