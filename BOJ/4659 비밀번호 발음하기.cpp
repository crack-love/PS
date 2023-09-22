// https://www.acmicpc.net/problem/4659

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p4659
{
	int main()
	{
		fastio;

		string vs = "aeiou";

		while (true)
		{
			string s;
			cin >> s;
			if (s == "end")
			{
				break;
			}

			bool hasv = false;
			bool hascon = false;
			bool hasdup = false;
			int concnt = 0;
			bool lastv = false;
			for1(i, s.size())
			{
				bool isv = false;
				for1(j, vs.size())
				{
					if (s[i] == vs[j])
					{
						hasv = isv = true;
						break;
					}
				}

				if (lastv == isv)
				{
					concnt += 1;
					if (concnt >= 3)
					{
						hascon = true;
						break;
					}
				}
				else
				{
					concnt = 1;
				}

				if (i > 0 && s[i - 1] == s[i] &&
					s[i] != 'o' && s[i] != 'e')
				{
					hasdup = true;
					break;
				}

				lastv = isv;
			}

			cout << "<" << s << ">" << " is ";
			cout << (!hasv || hascon || hasdup ? "not " : "");
			cout << "acceptable.\n";
		}

		return 0;
	}
};