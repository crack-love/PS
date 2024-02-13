// https://www.acmicpc.net/problem/17176

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p17176
{
	int main()
	{
		fastio;

		int des[53]{};
		int n;
		cin >> n;
		for1(i, n)
		{
			int x;
			cin >> x;
			des[x] += 1;
		}

		string s;
		getline(cin, s);
		getline(cin, s);
		for1(i, s.size())
		{
			if (isspace(s[i]))
			{
				des[0] -= 1;
			}
			else if (islower(s[i]))
			{
				des[s[i] - 'a' + 27] -= 1;
			}
			else if (isupper(s[i]))
			{
				des[s[i] - 'A' + 1] -= 1;
			}
		}

		for1(i, 53)
		{
			if (des[i] != 0)
			{
				cout << 'n';
				return 0;
			}
		}

		cout << 'y';
		return 0;
	}
};