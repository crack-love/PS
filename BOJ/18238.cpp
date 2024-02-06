// https://www.acmicpc.net/problem/18238

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p18238
{
	int main()
	{
		fastio;

		int k;
		cin >> k;
		for1(i, k)
		{
			int h;
			cin >> h;
			string s;
			cin >> s;

			cout << "Data Set " << i + 1 << ":\n";

			for1(j, s.size())
			{
				if (s[j] == 'c')
				{
					h += 1;
				}
				else if (s[j] == 'b')
				{
					h -= 1;
				}

				if (h <= 0)
				{
					h = 0;
					break;
				}
			}

			cout << h << "\n";
			cout << "\n";
		}

		return 0;
	}
};