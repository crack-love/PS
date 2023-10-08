// https://www.acmicpc.net/problem/10173

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p10173
{
	int main()
	{
		fastio;

		string line;
		while (true)
		{
			getline(cin, line);
			if (line == "EOI")
				return 0;

			for1(i, line.size())
			{
				line[i] = tolower(line[i]);
			}
			size_t p = line.find("nemo");
			cout << (p == line.npos ? "Missing" : "Found") << "\n";
		}

		return 0;
	}
};