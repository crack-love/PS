// https://www.acmicpc.net/problem/5026

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

struct p5026
{
	int main()
	{
		fastio;

		int n;
		cin >> n;
		while (n--)
		{
			string s;
			cin >> s;
			if (s == "P=NP")
			{
				cout << "skipped\n";
				continue;
			}

			int i = s.find('+');
			string as = s.substr(0, i);
			string bs = s.substr(i + 1);
			int a = stoi(as);
			int b = stoi(bs);
			cout << a + b << "\n";
		}

		return 0;
	}
};