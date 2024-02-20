// https://www.acmicpc.net/problem/11931

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p11931
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		priority_queue<int> q;
		cin >> n;
		for1(i, n)
		{
			int x;
			cin >> x;
			q.push(x);
		}

		for1(i, n)
		{
			cout << q.top() << "\n";
			q.pop();
		}

		return 0;
	}
};