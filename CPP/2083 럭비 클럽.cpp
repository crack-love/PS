// https://www.acmicpc.net/problem/2083

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2083
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		while (true)
		{
			string n;
			int a, b;
			cin >> n >> a >> b;

			if (n == "#" && a == 0 && b == 0)
				break;

			cout << n << " ";
			cout << (a > 17 || b >= 80 ? "Senior" : "Junior") << endl;
		}

		return 0;
	}
};