// https://www.acmicpc.net/problem/26264

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p26264
{
	int main()
	{
		fastio;

		int n;
		cin >> n;
		string s;
		cin >> s;
		int bc = 0, sc = 0;
		const string ss = "security", bs = "bigdata";

		for1(i, s.size())
		{
			if (s[i] == 's')
			{
				sc += 1;
				i += ss.size() - 1;
			}
			else if (s[i] == 'b')
			{
				bc += 1;
				i += bs.size() - 1;
			}
		}

		cout << (bc > sc ? "bigdata?" : (bc < sc ? "security!" : "bigdata? security!"));

		return 0;
	}
};