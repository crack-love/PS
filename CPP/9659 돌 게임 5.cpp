// https://www.acmicpc.net/problem/9659

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p9659
{
	int main()
	{
		fastio;

		ll n;
		cin >> n;

		// 1 3 5 7
		//  2 4 6
		if (n % 2 == 0)
		{
			cout << "CY";
		}
		else
		{
			cout << "SK";
		}

		return 0;
	}
};