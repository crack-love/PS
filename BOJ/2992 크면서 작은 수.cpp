// https://www.acmicpc.net/problem/2992

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

string x;
string v;
int visited;
string ans;
void dfs(int i)
{
	if (i == x.size())
	{
		if (v > x)
		{
			if (ans == "" || v < ans)
				ans = string(v);
		}
		return;
	}

	for (int j = 0; j < x.size(); ++j)
	{
		if ((visited & (1 << j)) > 0) continue;
		if (i == 0 && x[i] > x[j]) continue;

		v[i] = x[j];
		visited |= (1<<j);
		dfs(i + 1);
		visited &= ~(1<<j);
	}
}

int main()
{
	fastio;

	cin >> x;
	v = string(x);
	dfs(0);
	cout << (ans == "" ? "0" : ans);

	return 0;
}