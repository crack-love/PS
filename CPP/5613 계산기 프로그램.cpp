// https://www.acmicpc.net/problem/5613

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5613
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int v;
		cin >> v;
		while (true)
		{
			char op;
			cin >> op;
			if (op == '=')
				break;

			int v1;
			cin >> v1;
			if (op == '+')
				v += v1;
			else if (op == '-')
				v -= v1;
			else if (op == '*')
				v *= v1;
			else if (op == '/')
				v /= v1;
		}
		cout << v;

		return 0;
	}
};