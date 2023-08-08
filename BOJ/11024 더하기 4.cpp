// https://www.acmicpc.net/problem/11024

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p11024
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		string line;
		getline(cin, line);
		t = stoi(line);

		while (t--)
		{
			getline(cin, line);
			stringstream ss(line);

			int s = 0;
			while (!ss.eof())
			{
				int x;
				ss >> x;
				s += x;
			}
			cout << s << "\n";
		}

		return 0;
	}
};